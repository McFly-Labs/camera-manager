/*
 * This file is part of the Dronecode Camera Manager
 *
 * Copyright (C) 2017  Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <memory>
#include <string>
#include <vector>

#ifdef ENABLE_AVAHI
#include "avahi_publisher.h"
#include <avahi-common/watch.h>
#endif
#include "conf_file.h"
#include "rtsp_server.h"
#include "stream.h"

class StreamManager {
public:
    StreamManager(const ConfFile &conf);
    ~StreamManager();
    void start();
    void stop();
    void addStream(Stream *stream);

private:
    std::vector<std::unique_ptr<Stream>> streams;
    bool is_running;
#ifdef ENABLE_AVAHI
    AvahiPublisher avahi_publisher;
#endif
    RTSPServer rtsp_server;
};
