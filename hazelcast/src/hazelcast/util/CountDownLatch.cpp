//
// Created by sancar koyunlu on 8/15/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#include "hazelcast/util/Util.h"
#include "hazelcast/util/CountDownLatch.h"
#include <time.h>
namespace hazelcast {
    namespace util {
        CountDownLatch::CountDownLatch(int count)
        : count(count) {

        }

        void CountDownLatch::countDown() {
            --count;
        }

        bool CountDownLatch::await(int seconds) {
            time_t endTime = time(NULL) + seconds;
            while (endTime > time(NULL)) {
                if (count == 0) {
                    return true;
                }
                util::sleep(1);
            }
            if (count == 0) {
                return true;
            }
            return false;
        }

        void CountDownLatch::await() {
            while (true) {
                if (count == 0) {
                    break;
                }
                util::sleep(1);
            }
        }

        int CountDownLatch::get() {
            return count;
        }

        bool CountDownLatch::await(int seconds, int expectedCount) {
            while (seconds > 0 && count > expectedCount) {
                util::sleep(1);
                --seconds;
            }
            return count <= expectedCount;
        }
    }
}

