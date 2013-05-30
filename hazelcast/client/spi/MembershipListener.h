//
//  MembershipListener.h
//  cpp-client
//
//  Created by sancar koyunlu on 5/30/13.
//  Copyright (c) 2013 hazelcast. All rights reserved.
//

#ifndef HAZELCAST_MEMBERSHIP_LISTENER
#define HAZELCAST_MEMBERSHIP_LISTENER

namespace hazelcast {
    namespace client {
        
        namespace connection{
            class MembershipEvent;
        }
        namespace spi {
            
            class MembershipListener{
            public:
                virtual ~MembershipListener(){
                    
                };
                virtual void memberAdded(const hazelcast::client::connection::MembershipEvent& event) = 0;
                virtual void memberRemoved(const hazelcast::client::connection::MembershipEvent& event) = 0;
            };
        }
    }
}
#endif /* HAZELCAST_MEMBERSHIP_LISTENER */