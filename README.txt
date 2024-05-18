《參考資料》
https://www.taifex.com.tw/cht/index
https://www.taifex.com.tw/file/taifex/CHINESE/11/TechDocs/4/期交所TCPIP_TMP_v2.15.0.pdf

《演示代碼》
https://github.com/PeterW081/SdkTaifexMp2023/blob/master/subdir_Example/cxx_src_gtest/Example01_MsgLxx.cxx
https://github.com/PeterW081/SdkTaifexMp2023/blob/master/subdir_Example/cxx_src_gtest/Example02_Counter.cxx

《專案介紹》VERSION-0.08.019786
－－
　本案建置基於《臺灣期貨交易所 TCP/IP TMP 電文規範》的「第 2.15.0 版」，提供關於 TCP 電文通訊的系列編程介面（Api）。目的在於簡化期貨交易操作的程式代碼，且為初心者提供一個簡明易用的現成輪子。上述《電文規範》留有副本存於專案檔案中的 <RESOURCE> 目錄。
　本案積極利用語法特性，降低運行時的效能開銷，望能適應高頻交易之類的應用情境。積極使用 std::span 傳遞 TCP 電文，避免頻繁的記憶體拷貝。落於俗套地結合 Template、Constexpr，編譯期間儘量預先計算預先檢查，運行期間避免重複計算重複檢查。Template 之下，使用 StaticAssert 和 Concept 進行基礎的防呆。
　本案目前已有內容，主要是 TCP 電文的建模，以及基於所建模型的電文製作、電文收發（TCP收發）。具體用法，可見上文中的示範代碼。
－－
　TCP 電文建模，採用物件導向設計。
　＃RegexSearch："class.*::view::message::.*"
　電文本身包裝為物件類別，且有提供參照包裝物件（ReferenceWrapper）。參照包裝物件能夠指向已有 Buffer（ByteArray、CharArray），直接進行電文讀寫操作。如此可於網卡緩存直接讀寫 TCP 電文內容，減少記憶體拷貝次數，適應高頻通訊情境。
　＃RegexSearch："class.*::view02::(message|msg.*)::.*"
　電文操作封裝為物件實例函式（好過四散各處的靜態函式）。此中結合奇異遞歸模板模式（CRTP）、多重繼承、Concept，實現物件實例函式的後置設定。如此能以插件方式，對於特定型別—— Concept 斷言成功者——，疊加物件實例函式。電文操作封裝而成的物件實例函式，更加容易擴展，更加容易維護。
　＃RegexSearch：".*[LR].._FieldNo...*"
　電文建模代碼，具有設計適應 CodeReview 複查。電文原始模型，物件實例屬性名稱嚴格對照上述《電文規範》。電文原始模型的參照包裝物件，積極使用巨集（Macro）描述實體與參照間的對應關係。此中代碼行文雖然略為費解，但是便利第三方進行 CodeReview 複查，進而實現多方多重檢查；參與複查者可以不懂編程。此中費解部分已被妥善包裝，非為編程介面下的行文主體，故此無傷大雅。
－－
　TCP 電文收發，目前從簡設計。BoostAsio 之下實現 read timeout 邏輯。
　TCP 電文收發過程，目前僅有演示代碼提供參考。後續計畫使用有限狀態機（FSM）包裝電文收發過程，以使能夠模塊化地編寫不同情境下的應對邏輯。
－－
　目前缺乏應用環境，隔空開發頗為困難。有意合作者煩請聯繫以電子郵件，電子郵件地址為「racoontornado@outlook.com」。


