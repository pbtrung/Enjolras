/**************************************************************************************
 * Copyright (C) 2017 Trung Pham <me@trungbpham.com>                                  *
 * All rights reserved.                                                               *
 *                                                                                    *
 * Redistribution and use in source and binary forms, with or without                 *
 * modification, are permitted provided that the following conditions are met:        *
 *                                                                                    *
 *       * Redistributions of source code must retain the above copyright notice,     *
 *       this list of conditions and the following disclaimer.                        *
 *                                                                                    *
 *       * Redistributions in binary form must reproduce the above copyright notice,  *
 *       this list of conditions and the following disclaimer in the documentation    *
 *       and/or other materials provided with the distribution.                       *
 *                                                                                    *
 *       * Neither the name of Enjolras nor the names of its contributors may be used *
 *       to endorse or promote products derived from this software without specific   *
 *       prior written permission.                                                    *
 *                                                                                    *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"        *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE          *
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE     *
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE       *
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL         *
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR         *
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER         *
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,      *
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE      *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.               * 
 **************************************************************************************/

#include <iostream>

#include "sput.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/impl.h"
#include "yaml-cpp/node/convert.h"
#include "yaml-cpp/node/iterator.h"
#include "yaml-cpp/node/detail/impl.h"
#include "yaml-cpp/node/parse.h"

static void test_yaml_cpp_case_a();

void test_yaml_cpp()
{
    test_yaml_cpp_case_a();
}

static void test_yaml_cpp_case_a()
{
    YAML::Node test_yaml = YAML::LoadFile("test-yaml-cpp.yml");
    
    sput_fail_if(test_yaml["invoice"].as<int>() != 34843, "Case a: Test int read from YAML file");
}
