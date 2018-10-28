// Copyright (c) 2014-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gtest/gtest.h"

#include "wallet/wallet2.h"
#include "crypto/hash-invoice.h"
#include <string>
#include <vector>

using namespace crypto;

TEST(VATnumberValidation, Success)
{

  std::vector<char> file_data = { '1', '2', '3' };
  EXPECT_TRUE(hash_invoice(file_data, "01232") != boost::none);
  EXPECT_TRUE(hash_invoice(file_data, "asdfgh") == boost::none);
  EXPECT_TRUE(hash_invoice(file_data, "123456") != boost::none);

}


TEST(HashValidation, Success)
{

 std::string data_str = "6465206f6d6e69627573206475626974616e64756d";
 std::vector<char> data_arr(data_str.begin(), data_str.end());
 boost::optional<crypto::hash> result = hash_invoice(data_arr, "000000");
 EXPECT_EQ(std::string(result.get().data), "2f8e3df40bd11f9ac90c743ca8e32bb391da4fb98612aa3b6cdc000000000000");


 data_str = "6162756e64616e732063617574656c61206e6f6e206e6f636574";
 data_arr = std::vector<char>(data_str.begin(), data_str.end());
 result = hash_invoice(data_arr, "123456");
 EXPECT_EQ(std::string(result.get().data), "722fa8ccd594d40e4a41f3822734304c8d5eff7e1b528408e222010203040506");
}
