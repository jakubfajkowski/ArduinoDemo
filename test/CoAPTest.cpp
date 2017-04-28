#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CoAPTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../src/Frame.h"
#include "UdpEmulator.h"
#include "../src/Codes.h"

BOOST_AUTO_TEST_CASE(HeaderStructureTest) {
    Header header = {1,2,3,4,5};

    BOOST_ASSERT(header.Ver == 1);
    BOOST_ASSERT(header.T == 2);
    BOOST_ASSERT(header.TKL == 3);
    BOOST_ASSERT(header.Code == 4);
    BOOST_ASSERT(header.MessageId == 5);

    BOOST_ASSERT(sizeof(header) == 4);
}

BOOST_AUTO_TEST_CASE(HeaderSendingTest) {
    UdpEmulator emulator(64);
    Header expected = {1,2,3,4,5};

    emulator.write(&expected, sizeof(expected));

    Header actual;
    emulator.read(&actual, sizeof(Header));

    BOOST_ASSERT(expected.Ver == actual.Ver);
    BOOST_ASSERT(expected.T == actual.T);
    BOOST_ASSERT(expected.TKL == actual.TKL);
    BOOST_ASSERT(expected.Code == actual.Code);
    BOOST_ASSERT(expected.MessageId == actual.MessageId);
}

BOOST_AUTO_TEST_CASE(ArrayTest) {
    unsigned int expected_size = 10;
    ByteArray array(expected_size);
    unsigned int actual_size = array.size();
    BOOST_CHECK_EQUAL(expected_size, actual_size);
}

BOOST_AUTO_TEST_CASE(FrameSerializationTest) {
    unsigned int buffer_size = 64;

    Frame frame1;
    unsigned char expected[buffer_size];
    unsigned int bytes_written_expected = frame1.serialize(expected);
    unsigned char actual[buffer_size];
    unsigned int bytes_written_actual = frame1.serialize(actual);

    BOOST_CHECK_EQUAL(bytes_written_expected, bytes_written_actual);
    for (int i = 0; i < bytes_written_expected; ++i) {
        BOOST_CHECK_EQUAL(expected[i], actual[i]);
    }
}

BOOST_AUTO_TEST_CASE(UdpEmulatorTest) {
    UdpEmulator emulator(64);
    unsigned int expected = 1;
    emulator.write(&expected, sizeof(expected));
    unsigned int actual;
    emulator.read(&actual, sizeof(actual));

    BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EmptyFrameSendingTest) {
    UdpEmulator emulator(64);
    Frame expected;

    emulator.write(&expected, sizeof(expected));

    Frame actual;
    size_t packetSize = emulator.parsePacket() - 8;
    emulator.read(&actual, packetSize);

    BOOST_ASSERT(expected.getVer() == actual.getVer());
    BOOST_ASSERT(expected.getT() == actual.getT());
    BOOST_ASSERT(expected.getTKL() == actual.getTKL());
    BOOST_ASSERT(expected.getCode() == actual.getCode());
    BOOST_ASSERT(expected.getMessageId() == actual.getMessageId());
}

/*
BOOST_AUTO_TEST_CASE(SerializationTest) {
    UdpEmulator emulator(64);
    Frame expected;
    expected.setT(0);
    expected.setCode(CODE_GET);
    expected.setMessageId(11);

    unsigned char buffer[64];
    expected.serialize(buffer);

    std::cout << "Buffer: " << buffer << std::endl << "Size: " << sizeof(buffer) << std::endl;
    emulator.write(&expected, sizeof(expected));

    Frame actual;
    size_t packetSize = emulator.parsePacket() - 8;
    emulator.read(&actual, packetSize);
}
*/

/*
BOOST_AUTO_TEST_CASE(FrameSendingTest) {
    UdpEmulator emulator(64);
    Header header = {1,2,3,4,5};
    Frame expected;
    expected.header = header;
    expected.token = new unsigned char[3];
    expected.options = new unsigned char[4];
    expected.payload_marker = Frame::PAYLOAD_MARKER;
    expected.payload = new unsigned char[5];

    emulator.write(&expected, sizeof(expected));

    Frame actual;
    size_t packetSize = emulator.parsePacket() - 8;
    emulator.read(&actual, packetSize);

    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    BOOST_ASSERT(expected.header.Ver == actual.header.Ver);
    BOOST_ASSERT(expected.header.T == actual.header.T);
    BOOST_ASSERT(expected.header.TKL == actual.header.TKL);
    BOOST_ASSERT(expected.header.Code == actual.header.Code);
    BOOST_ASSERT(expected.header.MessageId == actual.header.MessageId);
}*/

#pragma clang diagnostic pop