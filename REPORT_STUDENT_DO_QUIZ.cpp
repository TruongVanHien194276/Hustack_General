// Problem: Report student doing quiz on date
// Description
// Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
// Input
// Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
// <yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
// Kết thúc dữ liệu là 1 dòng chứa dấu *
// Output
// Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
// (chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
// Example
// Input
// 2022-01-02 10:30:24 dungpq question1
// 2022-01-03 11:30:24 dungpq question1
// 2022-02-01 03:30:20 viettq question2
// 2022-02-01 03:35:20 viettq question1
// 2022-03-01 03:30:20 viettq question7
// 2022-01-02 11:20:24 viettq question2
// *
// Output
// 2022-01-02 2
// 2022-01-03 1
// 2022-02-01 2
// 2022-03-01 1

#include <bits/stdc++.h>

using namespace std;

struct Record {
    string date;
    string time;
    string user_id;
    string ques_id;

    bool operator<(Record& other) {
        return date < other.date;  
    }
};

int main(int argc, char const *argv[]){
    vector<Record> records;
    string date, time, user_id, ques_id;
    
    while (true) {
        cin >> date;
        if (date == "*") break;
        cin >> time >> user_id >> ques_id;

        records.push_back({date, time, user_id, ques_id});
    }

    sort(records.begin(), records.end());

    int cnt = 1;
    string lastDate = records[0].date;

    for (int i = 1; i < records.size(); i++) {
        if (records[i].date == lastDate) cnt++;
        else {
            cout << lastDate << " " << cnt << endl;
            lastDate = records[i].date;
            cnt = 1;  
        }
    }

    cout << lastDate << " " << cnt << endl;

    return 0;
}
