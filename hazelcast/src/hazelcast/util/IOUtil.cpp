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
//
//  Created by ihsan demir on 9/9/15.
//  Copyright (c) 2015 ihsan demir. All rights reserved.
//

#include "hazelcast/util/IOUtil.h"

namespace hazelcast {
    namespace util {
        void IOUtil::closeResource(Closeable *closable) {
            if (closable != NULL) {
                try {
                    closable->close();
                } catch (client::exception::IException& e) {
                    std::stringstream message;
                    message << "closeResource failed" << e.what();
                    ILogger::getLogger().finest(message.str());
                }

            }
        }
    }
}

