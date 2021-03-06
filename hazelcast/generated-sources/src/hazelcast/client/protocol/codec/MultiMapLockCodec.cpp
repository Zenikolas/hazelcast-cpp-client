/*
 * Copyright (c) 2008-2017, Hazelcast, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#include "hazelcast/client/protocol/codec/MultiMapLockCodec.h"
#include "hazelcast/client/exception/UnexpectedMessageTypeException.h"
#include "hazelcast/client/serialization/pimpl/Data.h"

namespace hazelcast {
    namespace client {
        namespace protocol {
            namespace codec {
                const MultiMapMessageType MultiMapLockCodec::RequestParameters::TYPE = HZ_MULTIMAP_LOCK;
                const bool MultiMapLockCodec::RequestParameters::RETRYABLE = false;
                const int32_t MultiMapLockCodec::ResponseParameters::TYPE = 100;
                std::auto_ptr<ClientMessage> MultiMapLockCodec::RequestParameters::encode(
                        const std::string &name, 
                        const serialization::pimpl::Data &key, 
                        int64_t threadId, 
                        int64_t ttl) {
                    int32_t requiredDataSize = calculateDataSize(name, key, threadId, ttl);
                    std::auto_ptr<ClientMessage> clientMessage = ClientMessage::createForEncode(requiredDataSize);
                    clientMessage->setMessageType((uint16_t)MultiMapLockCodec::RequestParameters::TYPE);
                    clientMessage->setRetryable(RETRYABLE);
                    clientMessage->set(name);
                    clientMessage->set(key);
                    clientMessage->set(threadId);
                    clientMessage->set(ttl);
                    clientMessage->updateFrameLength();
                    return clientMessage;
                }

                int32_t MultiMapLockCodec::RequestParameters::calculateDataSize(
                        const std::string &name, 
                        const serialization::pimpl::Data &key, 
                        int64_t threadId, 
                        int64_t ttl) {
                    int32_t dataSize = ClientMessage::HEADER_SIZE;
                    dataSize += ClientMessage::calculateDataSize(name);
                    dataSize += ClientMessage::calculateDataSize(key);
                    dataSize += ClientMessage::calculateDataSize(threadId);
                    dataSize += ClientMessage::calculateDataSize(ttl);
                    return dataSize;
                }

                MultiMapLockCodec::ResponseParameters::ResponseParameters(ClientMessage &clientMessage) {
                    if (TYPE != clientMessage.getMessageType()) {
                        throw exception::UnexpectedMessageTypeException("MultiMapLockCodec::ResponseParameters::decode", clientMessage.getMessageType(), TYPE);
                    }
                }

                MultiMapLockCodec::ResponseParameters MultiMapLockCodec::ResponseParameters::decode(ClientMessage &clientMessage) {
                    return MultiMapLockCodec::ResponseParameters(clientMessage);
                }

                MultiMapLockCodec::ResponseParameters::ResponseParameters(const MultiMapLockCodec::ResponseParameters &rhs) {
                }
                //************************ EVENTS END **************************************************************************//

            }
        }
    }
}

