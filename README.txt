《專案介紹》
　　本案建置基於《臺灣期貨交易所 TCP/IP TMP 電文規範》的「第 2.15.0 版」，用以簡化期貨交易系統的開發過程。目前因為缺乏時間和缺乏測試環境而中斷，希望以後能有機會完善。上述《電文規範》後續稱為 TCP 報文協定，留有副本存於專案檔案中的 <RESOURCE> 目錄。

　　該個專案目前主要內容，乃是基於上述 TCP 報文協定提供 API。在保證程式代碼的易維護性下，儘量提升程式代碼的運行效能，用以適應高頻交易之類的交易策略。程式代碼特點簡述如下：
　　物件導向設計，對於上述 TCP 報文協定中的報文，分別包裝了 Raw Object 和 Reference Objecet。提升程式碼可讀性以及便利 Code Review 時候核對代碼。其中類似 L41 的不定長度的 TCP 報文，花了一番功夫進行設計。
　　基於 C++ 特性，使用 Raw Array Reference 和 std::span 傳遞陣列資料。如此處理 TCP 報文期間，能夠避免頻繁的記憶體拷貝。
　　包裝了一些功能函式以收斂程式代碼，強化程式代碼的簡潔性以及一致性。避免相同操作的程式代碼，反覆拷貝之後衍生成為多個複雜費解的版本。此中功能函式，落於俗套地使用 C++ Template 和 C++ Constexpr，通過編譯時預處理以減少運行時的時間開銷。

　　承前所述，若是具有測試環境，本人可以繼續開發該個專案，至少能夠完成 TCP 報文收發，進一步可以實現測試用的 TcpClient 和 TcpServer。有意者請以電子郵件聯繫，電郵地址為「racoontornado@outlook.com」。

《參考資料》
https://www.taifex.com.tw/cht/index
https://www.taifex.com.tw/file/taifex/CHINESE/11/TechDocs/4/期交所TCPIP_TMP_v2.15.0.pdf
