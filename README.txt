《參考資料》
https://www.taifex.com.tw/cht/index
https://www.taifex.com.tw/file/taifex/CHINESE/11/TechDocs/4/期交所TCPIP_TMP_v2.15.0.pdf

《演示代碼》
https://github.com/PeterW081/SdkTaifexMp2023/tree/master/sTest-Example/cxx_xxx_example/
https://github.com/PeterW081/SdkTaifexMp2023/blob/master/sTest-Example/cxx_xxx_example/ExampleA1_MsgSession-Test03_WithFsm.cxx

《專案介紹》VERSION-0.08.020088
　－－
　本案基於《臺灣期貨交易所 TCP/IP TMP 電文規範》的「第 2.15.0 版」，旨在降低期貨電文操作的編程難度，且為初心者提供簡明易用的學習工具。此中《電文規範》留有副本存於 "./<RESOURCE>/" 目錄。
　目前內容，以 OSI 七層模型理解，乃是 L4、L5、L6 部份。目前進度可見上文《演示代碼》〔或見 "./subdir_Example/" 目錄〕；已經完成期交所系統連線驗證部份，略加拼裝即可執行期貨委託單的電文操作。
　－－
　本案 OSI-L4 部分，關於 Tcp 電文收發功能，簡單抽象一個物件介面，並且提供基於 BoostAsio 的跨平臺物件實作〔詳見：EzV4_TcpSocketerSync_V、EzV4_TcpSocketerSyncBoostAsio〕。遵循此中物件介面，另行實現 Tcp 電文收發功能，則可無縫替換本案提供實作。
　本案 OSI-L5 部分，通過 BoostMsm 以 Fsm〔狀態機〕控制電文收發過程。通過 MkV3_MsgSessionLayerALL_FsmSchema 可查電文序列的整體過程。通過 MsgSessionMsgProcessor 可查電文處理的具體執行；該個物件設計上用於收斂，關於特定電文的具體事務邏輯〔Ex：MsgR02 收到之後轉存資料庫〕。此中 Fsm 特色在於，可以使用同個狀態轉換過程描述 Server 和 Client 的電文收發過程，如此便於後期自行研發維護 TestServer。
　本案 OSI-L6 部分，電文建模分為兩層。裡層建模為最基礎的 CxxStruct，標識名稱嚴格對照《電文規範》，如此方便多方複查。表層建模為裡層建模的參照包裝，標識名稱更為靠近編程慣例，並且裝配基礎的電文內文編輯函式〔Ex：MsgR01 中的 OrderNo 賦值〕。此中電文建模，積極避免記憶體拷貝，直接於劃定的記憶體區域進行讀寫操作。
　－－
　本案目前卡在缺乏應用需求，隔空開發頗不務實。如有意向合作，煩請電郵聯繫以「racoontornado@outlook.com」。
