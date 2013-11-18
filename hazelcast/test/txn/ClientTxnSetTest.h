//
// Created by sancar koyunlu on 9/18/13.
// Copyright (c) 2013 hazelcast. All rights reserved.



#ifndef HAZELCAST_ClientTxnSetTest
#define HAZELCAST_ClientTxnSetTest

#include "iTest.h"
#include "ClientConfig.h"
#include "HazelcastInstance.h"

namespace hazelcast {
    namespace client {

        class HazelcastClient;

        namespace test {

            class HazelcastInstanceFactory;

            class ClientTxnSetTest : public iTest::iTestFixture<ClientTxnSetTest> {

            public:

                ClientTxnSetTest(HazelcastInstanceFactory&);

                ~ClientTxnSetTest();

                void addTests();

                void beforeClass();

                void afterClass();

                void beforeTest();

                void afterTest();

                void testAddRemove();

            private:
                HazelcastInstanceFactory& hazelcastInstanceFactory;
                HazelcastInstance instance;
                ClientConfig clientConfig;
                std::auto_ptr<HazelcastClient> client;
            };

        }
    }
}


#endif //HAZELCAST_ClientTxnSetTest