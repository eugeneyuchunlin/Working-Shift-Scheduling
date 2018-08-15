# Scheduling

# main.cpp
這是主程式
輸入班表月份：4，排班月份：5
目前權重已有調整
但是仍會發生Ｂ班接Ｃ班的情形。
大略算過發生準確對調解決B接C的情形的機率約為5％，期望值約9500次。

因為使用的資料結構尚未修好，所以編譯執行時很可能會發生segmentation fault，記憶體不足的情形。
建議使用linux系統編譯執行。
因為程式裡有使用C++11 extension range-based for loop。
所以編譯時請使用 g++ -std=c++11 -o main main.cpp。
如果您的電腦有裝intel compiler也可以使用 icpc -std=c++11 -o main  main.cpp。

# Calendar.csv
使用者需要在欲排定特休的日子中填入"Z"，其他W代表可以排入工作。
黃文松的班表是星期六日皆放假，有排特休就會有特休。

# Schedule.csv
這是上個月的班表
會全部讀入，最後排班表時會剩最後7天。

# next.csv
是下個月的班表
只有前七天。

# Rule.csv
這是月排班原則表
會全部讀入。
