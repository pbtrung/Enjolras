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

#include "test-cmdl-args.hpp"
#include "test-eigen.hpp"
#include "test-file-checker.hpp"
#include "test-yaml-cpp.hpp"

int main(int argc, char **argv)
{
    sput_start_testing();
    
    sput_enter_suite("test_cmdl_args()");
    sput_run_test(test_cmdl_args);
    
    sput_enter_suite("test_eigen()");
    sput_run_test(test_eigen);
    
    sput_enter_suite("test_file_checker()");
    sput_run_test(test_file_checker);
    
    sput_enter_suite("test_yaml_cpp()");
    sput_run_test(test_yaml_cpp);
    
    sput_finish_testing();
    
    return sput_get_return_value();    
}
