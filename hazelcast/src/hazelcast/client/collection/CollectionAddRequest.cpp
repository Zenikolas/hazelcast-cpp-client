//
// Created by sancar koyunlu on 9/12/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#include "CollectionAddRequest.h"
#include "PortableWriter.h"
#include "Data.h"
#include "CollectionPortableHook.h"

namespace hazelcast {
    namespace client {
        namespace collection {
            CollectionAddRequest::CollectionAddRequest(const std::string& name, const serialization::Data& data)
            : CollectionRequest(name)
            , data(data) {

            }

            int CollectionAddRequest::getClassId() const {
                return CollectionPortableHook::COLLECTION_ADD;
            }

            void CollectionAddRequest::writePortable(serialization::PortableWriter& writer) const {
                CollectionRequest::writePortable(writer);
                serialization::ObjectDataOutput & output = writer.getRawDataOutput();
                data.writeData(output);
            }
        }
    }
}