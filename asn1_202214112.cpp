#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    int id;
    string course_code, grade;
    float ct1, ct2, ct3, mid, best_ct, att_marks, per_marks, final_a, final_b, total, present;
    void best(){    best_ct = ct1 + ct2 + ct3 - (min({ct1, ct2, ct3}));    }
    void attendence_marks(){    att_marks = (present / 42.0) * 15;    }
    void performance_marks()
    {
        per_marks = ((mid / 30) * 15) - (42 - present);
        if (per_marks < 0)
            per_marks = 0;
    }
    void total_marks(){     total = (best_ct + mid + att_marks + per_marks + final_a + final_b);    }
    void grade_char()
    {
        if (total >= 240)
            cout << "A";
        else if (total >= 200)
            cout << "B";
        else if (total >= 160)
            cout << "C";
        else if (total >= 120)
            cout << "D";
        else if (total < 120)
            cout << "F";
        else
            cout << "E";
    }
    void print_marks()
    {
        cout << "\n\nAfter calculation \n\n";
        cout << "Attendence marks: " << att_marks << endl;
        cout << "Performance marks: " << per_marks << endl;
        cout << "Best 2 CT marks: " << best_ct << endl;
        cout << "Total (out of 300): " << total << endl;
        cout << "\n";
        cout << id << " Attained the grade: ";
        grade_char();
        cout << " in " << course_code << " with total marks (out of 300): " << total << endl;
    }
};
int main()
{
    student std, temp;
    cout << "Enter student id: ";
    cin >> std.id;
    cout << "Enter course code: ";
    cin.ignore();
    getline(cin, std.course_code);
    cout << "Enter Number of classes present in (out of 42): ";
    cin >> std.present;
    cout << "Enter CT-1 marks (out of 20, will be converted to 30): ";
    cin >> std.ct1;
    std.ct1 = (std.ct1 / 20) * 30;
    cout << "Enter CT-2 marks (out of 20, will be converted to 30): ";
    cin >> std.ct2;
    std.ct2 = (std.ct2 / 20) * 30;
    cout << "Enter CT-3 marks (out of 20, will be converted to 30): ";
    cin >> std.ct3;
    std.ct3 = (std.ct3 / 20) * 30;
    cout << "Enter Mid marks (out of 30): ";
    cin >> std.mid;
    cout << "Enter Final(Sec A) Marks (out of 90): ";
    cin >> std.final_a;
    cout << "Enter Final(Sec B) Marks (out of 90): ";
    cin >> std.final_b;
    std.best();
    std.attendence_marks();
    std.performance_marks();
    std.total_marks();
    std.print_marks();
    return 0;
}