#include <ostream>
#include "Frame.h"

Frame::Frame() {
    header_ = {DEFAULT_VERSION, 0, 0, 0, 0};
}

unsigned int Frame::serialize(unsigned char *buffer_begin) {
    unsigned char* buffer = buffer_begin;
    memcpy(buffer, &header_, sizeof(header_));
    buffer += sizeof(header_);

    insert(buffer, token_);
    insert(buffer, options_);

    if(payload_.size() > 0) {
        memcpy(buffer, &PAYLOAD_MARKER, sizeof(PAYLOAD_MARKER));
        buffer += sizeof(PAYLOAD_MARKER);
    }

    insert(buffer, payload_);

    return (unsigned int) (buffer - buffer_begin);
}

void Frame::insert(unsigned char *buffer, const ByteArray &array) {
    memcpy(buffer, array.begin(), array.size());
    buffer += array.size();
}

std::ostream& Frame::serialize(std::ostream& stream) {
    stream.write((char*)&header_, 4);
    stream.write((char*) token_.begin(), token_.size());
    stream.write((char*) options_.begin(), options_.size());
    stream.write((char*) payload_.begin(), payload_.size());
    return stream;

    //TODO: Compare two serialization methods above, choose better one and test it.
}

unsigned int Frame::getVer() const {
    return header_.Ver;
}

unsigned int Frame::getT() const {
    return header_.T;
}

void Frame::setT(unsigned int T) {
    header_.T = T;
}

unsigned int Frame::getTKL() const {
    return header_.TKL;
}

unsigned int Frame::getCode() const {
    return header_.Code;
}

void Frame::setCode(unsigned int Code) {
    header_.Code = Code;
}

unsigned int Frame::getMessageId() const {
    return header_.MessageId;
}

void Frame::setMessageId(unsigned int MessageId) {
    header_.MessageId = MessageId;
}

const ByteArray &Frame::getToken() const {
    return token_;
}

void Frame::setToken(const ByteArray &token) {
    Frame::token_ = token;
    Frame::header_.TKL = token.size();
}

const ByteArray &Frame::getOptions() const {
    return options_;
}

void Frame::setOptions(const ByteArray &options) {
    Frame::options_ = options;
}

const ByteArray &Frame::getPayload() const {
    return payload_;
}

void Frame::setPayload(const ByteArray &payload) {
    Frame::payload_ = payload;
}

