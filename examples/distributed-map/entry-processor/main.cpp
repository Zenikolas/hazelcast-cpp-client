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
// Created by İhsan Demir on 21/12/15.
//
#include <hazelcast/client/HazelcastClient.h>

#include "Employee.h"

class EmployeeRaiseEntryProcessor : public hazelcast::client::serialization::IdentifiedDataSerializable {
public:
    int getFactoryId() const {
        return 1;
    }

    int getClassId() const {
        return 6;
    }

    void writeData(hazelcast::client::serialization::ObjectDataOutput &writer) const {
    }

    void readData(hazelcast::client::serialization::ObjectDataInput &reader) {
    }
};


int main() {
    hazelcast::client::ClientConfig config;
    hazelcast::client::HazelcastClient hz(config);

    hazelcast::client::IMap<std::string, Employee> employees = hz.getMap<std::string, Employee>("employees");

    employees.put("John", Employee(1000));
    employees.put("Mark", Employee(1000));
    employees.put("Spencer", Employee(1000));

    EmployeeRaiseEntryProcessor processor;
    std::map<std::string, boost::shared_ptr<int> > result =
            employees.executeOnEntries<int, EmployeeRaiseEntryProcessor>(processor);

    std::cout << "The result after employees.executeOnEntries call is:" << std::endl;
    for (std::map<std::string, boost::shared_ptr<int> >::const_iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << it->first << " salary: " << *it->second << std::endl;
    }

    std::set<std::string> keys;
    keys.insert("John");
    keys.insert("Spencer");

    result = employees.executeOnKeys<int, EmployeeRaiseEntryProcessor>(keys, processor);

    std::cout << "The result after employees.executeOnKeys call is:" << std::endl;
    for (std::map<std::string, boost::shared_ptr<int> >::const_iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << it->first << " salary: " << *it->second << std::endl;
    }

    std::cout << "Finished" << std::endl;

    return 0;
}
