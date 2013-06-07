//
//  ConstantSerializers.h
//  Server
//
//  Created by sancar koyunlu on 1/10/13.
//  Copyright (c) 2013 sancar koyunlu. All rights reserved.
//

#ifndef HAZELCAST_CONSTANT_SERIALIZERS
#define HAZELCAST_CONSTANT_SERIALIZERS

#include "SerializationConstants.h"
#include <vector>
#include <string>

namespace hazelcast {
    namespace client {
        namespace serialization {


            typedef unsigned char byte;

            template<typename T>
            int getTypeSerializerId(const T& t) {
                return SerializationConstants::CONSTANT_TYPE_PORTABLE;
            };

            template<typename T>
            int getFactoryId(const T& t) {
                return 0;
            }

            template<typename T>
            int getClassId(const T& t) {
                return 0;
            }

            int getTypeSerializerId(byte data);

            int getTypeSerializerId(bool data);

            int getTypeSerializerId(char data);

            int getTypeSerializerId(short data);

            int getTypeSerializerId(int data);

            int getTypeSerializerId(long data);

            int getTypeSerializerId(float data);

            int getTypeSerializerId(double data);

            int getTypeSerializerId(const std::string&   data);

            int getTypeSerializerId(const std::vector<byte>&  data);

            int getTypeSerializerId(const std::vector<char >&  data);

            int getTypeSerializerId(const std::vector<short >&  data);

            int getTypeSerializerId(const std::vector<int>&  data);

            int getTypeSerializerId(const std::vector<long >&  data);

            int getTypeSerializerId(const std::vector<float >&  data);

            int getTypeSerializerId(const std::vector<double >&  data);

        }
    }
}

#include "ConstantSerializers/ConstantClassDefinitionWriter.h"
#include "ConstantSerializers/ConstantDataOutput.h"
#include "ConstantSerializers/ConstantPortableWriter.h"
#include "ConstantSerializers/ConstantsPortableReader.h"
#include "ConstantSerializers/ConstantsMorphingPortableReader.h"
#include "ConstantSerializers/ConstantDataInput.h"

#endif /* HAZELCAST_CONSTANT_SERIALIZERS */
