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

#include "Eigen/Eigen.hpp"
#include "Eigen/Dense"

using namespace Eigen;

static void test_eigen_case_a();

void test_eigen()
{
    test_eigen_case_a();
}

static void test_eigen_case_a()
{
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    sput_fail_if(m(0,0) != 3, "Case a: Test matrix element value");
    sput_fail_if(m(1,1) != 1.5, "Case a: Test matrix element operation");
    
    VectorXd v(2);
    v(0) = 4;
    v(1) = v(0) - 1;
    sput_fail_if(v(0) != 4, "Case a: Test vector element value");
    sput_fail_if(v(1) != 3, "Case a: Test vector element operation");    
}
