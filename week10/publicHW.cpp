#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 10

class BOOK{
private:
    string bookID;
    string title;
    string author;
    int year; 

public:
    // Constructor without parameters
    BOOK() : bookID(""), title(""), author(""), year(0){}

    // Constructor with parameters
    BOOK (string i, string t, string a, int y) : bookID(i), title(t), author(a), year(y){}
    
    void inputBook(){
        cin.ignore();
        cout << "Nhap ma sach       : "; getline (cin, bookID);
        cout << "Nhap ten sach      : "; getline (cin, title);
        cout << "Nhap ten tac gia   : "; getline (cin, author);
        cout << "Nhap nam xuat ban  : "; cin >> year;
    }

    // 2. Hiển thị thông tin 1 quyển sách
    void displayBook() const {
        cout << bookID << "\t\t" << title << "\t\t" << author << "\t\t" << year << endl;
    }

    // Getter lấy mã sách để phục vụ tìm kiếm ở hàm main
    string getBookID () const {return bookID;}
};

int main(){
    vector <BOOK> list;
    int n;
    cout << "Nhap so luong sach : ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n ; i++){
        BOOK b("", "", "", 0);  // constructor
        cout << " === Nhap thong tin sach " << i + 1 << " ===" << endl;
        b.inputBook() ;     // gọi hàm public
        list.push_back(b);  // Lưu danh sách vào f
    }

    while (true){
    cout << "\n===== QUAN LY SACH THU VIEN =====" << endl;
    cout << " 1. Them sach" << endl;
    cout << " 2. Hien thi danh sach sach" << endl;
    cout << " 3. Tim sach theo ma sach" << endl;
    cout << " 4. Thoat" << endl;

    int choice;
    cout << "Chon chuc nang: "; cin >> choice;
    cin.ignore();
    
    if (choice == 1){
        BOOK b;
        cout << "\n === THEM SACH MOI ===" << endl;
        b.inputBook();
        list.push_back(b);
        cout << "\n --> Them sach thanh cong!" << endl;
    }
    else if (choice == 2){
        if (list.empty()){
            cout << "Danh sach hien dang trong" << endl;
        }
        else{
            cout << "\n === DANH SACH SACH ===" << endl;
            cout << "Ma sach\t\tTen sach\t\tTac gia\t\tNam XB\n";
            for (const BOOK& b : list){
                b.displayBook();
            }
        }
    }
    else if (choice == 3){
        cout << "Nhap id sach can tim: ";
        string idSearch; getline (cin, idSearch);

        bool found  = false;
        for (const BOOK& b : list){
            if (b.getBookID() == idSearch){
                cout << "\n --> Da tim thay sach: " << endl;
                cout << "Ma sach\t\tTen sach\t\tTac gia\t\tNam XB\n";
                b.displayBook();
                found = true;
                break;
            }
        }
        if (!found){
            cout << "\n --> Khong tim thay sach nao co ma: " << idSearch << endl;
        }
    }

    else if (choice == 4){
        cout << "Thoat chuong trinh" << endl;
        break;
    }
    else {
        cout << "Lua chon khong hop le, vui long chon lai" << endl;
    }
    }
    return 0;
}