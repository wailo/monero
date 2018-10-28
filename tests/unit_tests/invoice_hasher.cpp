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
// #include "common/dns_utils.h"
// #include "simplewallet/simplewallet.h"
#include <string>

TEST(VATnumberValidation, Success)
{
  cryptonote::simple_wallet wallet;
  EXPECT_TRUE(wallet.hash_invoice("invoice_hasher.cpp", "01232") == boost::none);
  EXPECT_TRUE(wallet.hash_invoice("invoice_hasher.cpp", "asdfgh") == boost::none);
  EXPECT_TRUE(wallet.hash_invoice("invoice_hasher.cpp", "123456") != boost::none);

}


TEST(HashValidation, Success)
{
  // cryptonote::simple_wallet wallet;
  // auto hash = wallet.hash_invoice("invoice_hasher.cpp", "012345");
  // std::sstring hash_str;
  // hash_str << hash.get();
  
  // EXPECT_STREQ
  EXPECT_EQ(wallet.hash_invoice("invoice_hasher.cpp", "01232")  == boost::none, true);
  EXPECT_EQ(wallet.hash_invoice("invoice_hasher.cpp", "asdfgh") == boost::none, true);
  EXPECT_EQ(wallet.hash_invoice("invoice_hasher.cpp", "123456") == boost::none, false);
}
