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

#include "utils/cmdl-args.hpp"

void CmdlArgs::print_suggestion(char *program_name)
{
    std::cout << "Try '" << program_name << " --help' to see all options.\n" << std::endl;
    exit(EXIT_FAILURE);
}

void CmdlArgs::make_options(int argc, char *argv[])
{
    try {
        
        options.add_options()
            ("i,input", "Input file name (required)", cxxopts::value<std::string>())
            ("o,output", "Output file name (optional)", cxxopts::value<std::string>()
                ->default_value("enjolras.out"))
            ("l,log", "Log file name (optional)", cxxopts::value<std::string>()
                ->default_value("enjolras.log"))
            ("h,help", "Print help")
            ("v,version", "Print version");
        options.parse(argc, argv);
        
        print_help(options, argv);
        print_version(options, argv);

        validate_input(options, argv);
        validate_output(options, argv);
        validate_log(options, argv);
        
    } catch (const cxxopts::OptionException& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        print_suggestion(argv[0]);
    }
}

void CmdlArgs::validate_input(cxxopts::Options options, char *argv[])
{
    if(options.count("input") == 1) {
        input_filename = options["input"].as<std::string>();
    } else if(options.count("input") == 0) {
        std::cout << "ERROR: Input file is required." << std::endl;
        print_suggestion(argv[0]);
    } else if(options.count("input") > 1) {
        std::cout << "ERROR: " << argv[0] << " only accepts ONE input file." << std::endl;
        print_suggestion(argv[0]);
    }
}

void CmdlArgs::validate_output(cxxopts::Options options, char *argv[])
{
    if(options.count("output") <= 1) {
        output_filename = options["output"].as<std::string>();
    } else {
        std::cout << "ERROR: " << argv[0] << " only accepts ONE output file." << std::endl;
        print_suggestion(argv[0]);
    }
}

void CmdlArgs::validate_log(cxxopts::Options options, char *argv[])
{
    if(options.count("log") <= 1) {
        log_filename = options["log"].as<std::string>();
    } else {
        std::cout << "ERROR: " << argv[0] << " only accepts ONE log file." << std::endl;
        print_suggestion(argv[0]);
    }
}

void CmdlArgs::print_help(cxxopts::Options options, char *argv[])
{
    int op_count = options.count("input") + options.count("output")
                 + options.count("log") + options.count("version");
               
    if(options.count("help") == 1 && op_count > 0) {
        std::cout << "ERROR: " << "Mixing '-h, --help' with other options is not allowed." << std::endl;
        print_suggestion(argv[0]);
    }
    if(options.count("help") > 1) {
        std::cout << "ERROR: " << "More than ONE '-h, --help' is not allowed." << std::endl;
        print_suggestion(argv[0]);
    }
    if(options.count("help") == 1) {
        std::cout << options.help({"", "Group"});
        exit(EXIT_SUCCESS);
    }
}

void CmdlArgs::print_version(cxxopts::Options options, char *argv[])
{
    int op_count = options.count("input") + options.count("output")
                 + options.count("log") + options.count("help");
                 
    if(options.count("version") > 1) {
        std::cout << "ERROR: " << "More than ONE '-v, --version' is not allowed." << std::endl;
        print_suggestion(argv[0]);
    }
    if(options.count("version") == 1 && op_count > 0) {
        std::cout << "ERROR: " << "Mixing '-v, --version' with other options is not allowed." << std::endl;
        print_suggestion(argv[0]);
    }
    if(options.count("version") == 1) {
        std::cout << "Enjolras " << ENJOLRAS_VERSION << std::endl;
        std::cout << "C++ Finite Element Analysis Program" << std::endl;
        std::cout << "Copyright (C) 2017 Trung Pham <me@trungbpham.com>" << std::endl;
        std::cout << "This is free software; see the source for copying conditions. There is NO\n"
                    "warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
                  << std::endl;
        exit(EXIT_SUCCESS);
    }
}

std::string CmdlArgs::get_input_filename()
{
    return input_filename;
}

std::string CmdlArgs::get_output_filename()
{
    return output_filename;
}

std::string CmdlArgs::get_log_filename()
{
    return log_filename;
}
