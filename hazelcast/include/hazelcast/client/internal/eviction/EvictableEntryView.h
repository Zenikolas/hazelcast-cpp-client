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
#ifndef HAZELCAST_CLIENT_INTERNAL_EVICTION_EVICTABLEENTRYVIEW_H_
#define HAZELCAST_CLIENT_INTERNAL_EVICTION_EVICTABLEENTRYVIEW_H_

#include <assert.h>
#include <stdint.h>

#include <boost/shared_ptr.hpp>

#if  defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(push)
#pragma warning(disable: 4251) //for dll export
#endif

namespace hazelcast {
    namespace client {
        namespace internal {
            namespace eviction {
                /**
                * Contract point (from the end user perspective) for serving/accessing entries that can be evicted.
                *
                * @param <K> the type of the key
                * @param <V> the type of the value
                */
                template <typename K, typename V>
                class EvictableEntryView {
                public:
                    virtual ~EvictableEntryView() { }

                    /**
                     * Gets the creation time of this {@link EvictableEntryView} in milliseconds.
                     *
                     * @return the creation time of this {@link EvictableEntryView} in milliseconds
                     */
                    virtual int64_t getCreationTime() const = 0;

                    /**
                     * Gets the latest access time difference of this {@link EvictableEntryView} in milliseconds.
                     *
                     * @return the latest access time of this {@link EvictableEntryView} in milliseconds
                     */
                    virtual int64_t getLastAccessTime() const = 0;

                    /**
                     * Gets the access hit count of this {@link EvictableEntryView}.
                     *
                     * @return the access hit count of this {@link EvictableEntryView}
                     */
                    virtual int64_t getAccessHit() const = 0;

                    /**
                     * Gets the key of the entry.
                     *
                     * @return the key of the entry
                     */
                    virtual boost::shared_ptr<K> getKey() const {
                        assert(0);
                        return boost::shared_ptr<K>();
                    }

                    /**
                     * Gets the value of the entry.
                     *
                     * @return the value of the entry
                     */
                    virtual boost::shared_ptr<V> getValue() const {
                        assert(0);
                        return boost::shared_ptr<V>();
                    }
                };
            }
        }
    }
};

#if  defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(pop)
#endif 

#endif /* HAZELCAST_CLIENT_INTERNAL_EVICTION_EVICTABLEENTRYVIEW_H_ */
