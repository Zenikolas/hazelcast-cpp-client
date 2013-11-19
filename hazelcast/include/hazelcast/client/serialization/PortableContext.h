//
// Created by sancar koyunlu on 5/2/13.
// Copyright (c) 2013 sancar koyunlu. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef HAZELCAST_PORTABLE_CONTEXT
#define HAZELCAST_PORTABLE_CONTEXT

#include "ConcurrentMap.h"
#include <vector>
#include <map>


namespace hazelcast {
    namespace client {
        namespace serialization {

            class ClassDefinition;

            class SerializationContext;

            typedef unsigned char byte;

            class PortableContext {
            public:

                PortableContext();

                ~PortableContext();

                PortableContext(SerializationContext *serializationContext);

                bool isClassDefinitionExists(int, int) const;

                ClassDefinition *lookup(int, int);

                ClassDefinition *createClassDefinition(std::auto_ptr< std::vector<byte> >);

                ClassDefinition *registerClassDefinition(ClassDefinition *);

            private:
                void compress(std::vector<byte>&);

                long long combineToLong(int x, int y) const;

                int extractInt(long long value, bool lowerBits) const;

                std::vector<byte> decompress(std::vector<byte> const &) const;

                hazelcast::util::ConcurrentMap<long long, ClassDefinition> versionedDefinitions;

                SerializationContext *serializationContext;
            };
        }
    }
}

#endif //HAZELCAST_PORTABLE_CONTEXT
