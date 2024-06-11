《參考資料》
https://www.taifex.com.tw/cht/index
https://www.taifex.com.tw/file/taifex/CHINESE/11/TechDocs/4/期交所TCPIP_TMP_v2.15.0.pdf

《演示代碼》
https://github.com/PeterW081/SdkTaifexMp2023/tree/master/subdir_Example/cxx_src_example/
https://github.com/PeterW081/SdkTaifexMp2023/blob/master/subdir_Example/cxx_src_example/Example01_03MsgLxxFsmBothEndpoint.cxx

《專案介紹》VERSION-0.08.019879
　－－
　本案建置基於《臺灣期貨交易所 TCP/IP TMP 電文規範》的「第 2.15.0 版」，主要目的在於降低期貨電文收發系統的編程難度，且為初心者提供一個簡明易用的現成輪子。此中《電文規範》留有副本存於 "./<RESOURCE>/" 目錄。
　本案目前內容，主要是 TCP 電文的電文建模，以及基於所建模型的系列電文操作。電文操作目前已有，電文製作、電文收發（TCP收發）、電文收發過程控制（FSM控制）。此中提供編程介面（Api），可見上文中的演示代碼，或見 "./subdir_Example/cxx_src_example/" 目錄下的演示代碼。
　－－
　TCP 電文建模，採用物件導向設計。主要使用如下設計模式，轉接器模式（Adapter Pattern）、裝飾者模式（Decorator Pattern）。
　＃RegexSearch："class.*::view::message::.*"
　電文本身包裝為物件類別，且有提供參照包裝物件（ReferenceWrapper）。參照包裝物件能夠指向已有 Buffer（Ex：CharArray），直接進行電文讀寫操作。如此減少記憶體拷貝次數，且可直接讀寫電文於網卡緩存。參照包裝物件對原始物件，使用 Reference 設置物件實例屬性別名。如此便於配合其他編程介面（尤其涉及泛型機制的編程介面）。
　＃RegexSearch："class.*::view02::(message|msg.*)::.*"
　電文操作封裝為物件實例函式（好過四散各處的靜態函式）。此中結合奇異遞歸模板模式（CRTP）、多重繼承、Concept，實現物件實例函式的後置植入。如此電文物件下的電文操作函式，更加容易擴展，更加容易維護。
　＃RegexSearch：".*[LR].._FieldNo...*"
　電文建模代碼，具有設計適應 CodeReview 複查。電文原始物件，物件實例屬性名稱嚴格對照上述《電文規範》。如此方便第三方進行 CodeReview 複查（第三方可非軟體工程師），實現事務邏輯代碼的多方複查。此中代碼已被妥善封裝，且非程式代碼中的行文主體，整體而言無傷大雅。
　－－
　TCP 電文收發，目前從簡設計。電文收發，使用 Sync 通訊模式。電文收發過程控制，使用有限狀態機（FSM）。代碼行文注重簡明易懂，以使開發動能更多聚焦於事務邏輯，且讓初心者更快進入狀態。
　＃RegexSearch："namespace.*network;.*typename.*EzV2_TcpBothEndpointMsg_Sync.*"
　電文收發，使用 BoostAsio 實踐。BoostAsio 之下，使用 Async Api 實踐 Sync Func。如此實踐 write/read timeout 功能，以及簡化控制過程的代碼。BoostAsio 之下，前後兩端皆有實踐，且以同套 Api 包裝功能。簡單情境之下，兩端代碼鏡像對稱。
　＃RegexSearch："namespace.*fsm_msg_transfer_flow.*"
　電文收發過程控制，使用 BoostMsm 實踐。目前完成 LinkLayer 部分，其他部分仍在作業。此中使用 Fsm 將整個電文收發過程切片為系列職能明確的 FsmAction 函式，且能使用同套 Fsm 描述 tcp 前後兩端的控制過程。此中代碼行文體現，tcp 前後兩端之間電文收發及其電文收發過程，所具有的鏡像對稱特性。代碼追蹤維護時候，基於某端的 FsmAction，能夠快速定位到對端的 FsmAction。
　－－
　本案目前缺乏應用環境，隔空開發頗不務實。如有意向合作，可以通過電子郵件聯絡，電子郵件地址為「racoontornado@outlook.com」。
