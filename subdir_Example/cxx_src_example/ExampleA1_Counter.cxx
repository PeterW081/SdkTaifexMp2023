#include <gtest/gtest.h>
#pragma

#include "xplum_model/taifex_msg_proto/structure_message/msg_rxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_common.h"
#include "xplum_sdkit/taifex_msg_proto/view02/msg_all_layer.h"

namespace nscxx
{
using namespace xplum_model::taifex_msg_proto;
using namespace xplum_sdkit::taifex_msg_proto;
}

TEST (ExampleA1_Counter, Test01_MsgSeq)
{
  // init
  std::vector<nscxx::message::R01> arr_msg = {
    nscxx::message::R01 (),
    nscxx::message::R01 (),
    nscxx::message::R01 (),
  };

  // CounterMsgSeqNumSimple, MsgSeqNum,
  std::shared_ptr seed = std::make_shared<nscxx::kitbag::CounterMsgSeqNumSimple> ();
  for (auto &msg : arr_msg)
    {
      auto msg_view = nscxx::view02::message::R01 (msg);
      msg_view.fx_assign_m_msg_seq_num_0_seed (*seed);
    }
  std::cout << arr_msg[0].hdr.MsgSeqNum << std::endl;
  std::cout << arr_msg[1].hdr.MsgSeqNum << std::endl;
  std::cout << arr_msg[2].hdr.MsgSeqNum << std::endl;

  // test
  std::vector<std::size_t> arr_value_test;
  std::vector<std::size_t> arr_value_expect = { 1, 2, 3 };
  for (auto &msg : arr_msg)
    {
      arr_value_test.emplace_back () = msg.hdr.MsgSeqNum;
    }
  EXPECT_EQ (arr_value_test, arr_value_expect);
}

TEST (ExampleA1_Counter, Test02_OrderSeq_OrderNo)
{
  // init
  std::vector<nscxx::message::R01> arr_msg = {
    nscxx::message::R01 (),
    nscxx::message::R01 (),
    nscxx::message::R01 (),
  };

  // CounterOrderSeqSimple, OrderNo,
  std::shared_ptr seed = std::make_shared<nscxx::kitbag::CounterOrderSeqSimple> ();
  for (auto &msg : arr_msg)
    {
      auto msg_view = nscxx::view02::message::R01 (msg);
      msg_view.fx_assign_m_order_seq_0_seed (*seed);
    }
  std::cout << std::string (arr_msg[0].order_no, 5) << ", " << arr_msg[0].ord_id << std::endl;
  std::cout << std::string (arr_msg[1].order_no, 5) << ", " << arr_msg[1].ord_id << std::endl;
  std::cout << std::string (arr_msg[2].order_no, 5) << ", " << arr_msg[2].ord_id << std::endl;

  // test
  std::vector<std::tuple<std::string, std::size_t> > arr_value_test;
  std::vector<std::tuple<std::string, std::size_t> > arr_value_expect = { { "00000", 1 }, { "00001", 1 }, { "00002", 1 } };
  for (auto &msg : arr_msg)
    {
      auto &element = arr_value_test.emplace_back ();
      std::get<0> (element) = std::string (msg.order_no, 5);
      std::get<1> (element) = msg.ord_id;
    }
  EXPECT_EQ (arr_value_test, arr_value_expect);
}

TEST (ExampleA1_Counter, Test03_OrderSeq_OrderId)
{
  // init
  std::vector<nscxx::message::R01> arr_msg = {
    nscxx::message::R01 (),
    nscxx::message::R01 (),
    nscxx::message::R01 (),
  };

  // CounterOrderSeqSimple, OrderNo,
  std::shared_ptr seed = std::make_shared<nscxx::kitbag::CounterOrderSeqSimple> ();
  for (auto &msg : arr_msg)
    {
      auto msg_view = nscxx::view02::message::R01 (msg);
      msg_view.fx_assign_m_order_seq_0_seed (*seed, "00005");
    }
  std::cout << std::string (arr_msg[0].order_no, 5) << ", " << arr_msg[0].ord_id << std::endl;
  std::cout << std::string (arr_msg[1].order_no, 5) << ", " << arr_msg[1].ord_id << std::endl;
  std::cout << std::string (arr_msg[2].order_no, 5) << ", " << arr_msg[2].ord_id << std::endl;

  // test
  std::vector<std::tuple<std::string, std::size_t> > arr_value_test;
  std::vector<std::tuple<std::string, std::size_t> > arr_value_expect = { { "00005", 1 }, { "00005", 2 }, { "00005", 3 } };
  for (auto &msg : arr_msg)
    {
      auto &element = arr_value_test.emplace_back ();
      std::get<0> (element) = std::string (msg.order_no, 5);
      std::get<1> (element) = msg.ord_id;
    }
  EXPECT_EQ (arr_value_test, arr_value_expect);
}
