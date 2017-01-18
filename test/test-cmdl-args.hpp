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

#include "sput.h"
#include "utils/cmdl-args.hpp"

static void test_cmdl_args_case_a();
static void test_cmdl_args_case_b();

void test_cmdl_args()
{
    test_cmdl_args_case_a();
    test_cmdl_args_case_b();
}

static void test_cmdl_args_case_a()
{
    std::string tmp[] = {"enjolras", "-i", "input.txt"};
    const int argc = sizeof(tmp)/sizeof(tmp[0]);
    char *argv[argc];
    for(int i = 0; i < argc; i++) {
        argv[i] = (char *)malloc(20);
        strcpy(argv[i], tmp[i].c_str());
    }
    
    CmdlArgs cmdl_args(argv[0], "Enjolras - C++ Finite Element Analysis Program.");
    cmdl_args.make_options(argc, argv);
    std::string input_filename = cmdl_args.get_input_filename();
    sput_fail_if(input_filename.compare(tmp[2]) != 0, "Case a: Input file name");
    std::string output_filename = cmdl_args.get_output_filename();
    std::string tmp_out("enjolras.out");
    sput_fail_if(output_filename.compare(tmp_out) != 0, "Case a: Output file name");
    std::string log_filename = cmdl_args.get_log_filename();
    tmp_out = "enjolras.log";
    sput_fail_if(log_filename.compare(tmp_out) != 0, "Case a: Log file name");
    
    for(int i = 0; i < argc; i++) {
        free(argv[i]);
    }
}

static void test_cmdl_args_case_b()
{
    std::string tmp[] = {"enjolras", "-i", "input.txt", "-o", "output.txt"};
    const int argc = sizeof(tmp)/sizeof(tmp[0]);
    char *argv[argc];
    for(int i = 0; i < argc; i++) {
        argv[i] = (char *)malloc(20);
        strcpy(argv[i], tmp[i].c_str());
    }
    
    CmdlArgs cmdl_args(argv[0], "Enjolras - C++ Finite Element Analysis Program.");
    cmdl_args.make_options(argc, argv);
    std::string input_filename = cmdl_args.get_input_filename();
    sput_fail_if(input_filename.compare(tmp[2]) != 0, "Case b: Input file name");
    std::string output_filename = cmdl_args.get_output_filename();
    sput_fail_if(output_filename.compare(tmp[4]) != 0, "Case b: Output file name");
    std::string log_filename = cmdl_args.get_log_filename();
    std::string tmp_out("enjolras.log");
    sput_fail_if(log_filename.compare(tmp_out) != 0, "Case b: Log file name");
    
    for(int i = 0; i < argc; i++) {
        free(argv[i]);
    }
}
