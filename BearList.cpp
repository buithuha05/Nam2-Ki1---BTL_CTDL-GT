#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include "Bear.cpp"

using namespace std;

class BearList {
private:
    list<Bear> bears;

public:
    // Nhap du lieu vao danh sach
    void Nhap() {
        int size;
        cout << "Nhap so luong bear: ";
        cin >> size;
        for (int i = 0; i < size; ++i) {
            Bear b;
            cout << "Nhap thong tin cho bear thu " << i + 1 << ":\n";
            cin >> b;
            bears.push_back(b);
        }
    }

    // Doc du lieu tu file vao danh sach
    void readFile(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "***Khong the mo tep tin.\n";
            return;
        }
        Bear b;
        while (file >> b) {
            bears.push_back(b);
        }
        file.close();
    }

    // Xuat du lieu ra man hinh va file
    void Xuat() const {
        // Xuat du lieu ra man hinh
        cout << "\n=== Danh sach bear trong bo nho ===\n";
        for (const auto& bear : bears) {
            cout << bear << endl;
        }

        // Doc du lieu tu file khohang.txt va xuat
        cout << "\n=== Danh sach bear trong file khohang.txt ===\n";
        ifstream file("khohang.txt");
        if (!file.is_open()) {
            cout << "***Khong the mo tep tin khohang.txt.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;  // In ra tung dong trong file
        }
        file.close();
    }

    // Sap xep danh sach theo ten
    void SapXep() {
    	// Sap xep danh sach theo ten
    	bears.sort([](const Bear& a, const Bear& b) {
    	    return a.getTenBear() < b.getTenBear();
    	});

    	// In danh sach da sap xep ra man hinh
    	cout << "***Danh sach bear sau khi sap xep theo ten:\n";
    	for (const auto& bear : bears) {
    	    cout << bear << "\n";
    	}
	}


    // Them bear vao danh sach
    void ThemBear(const Bear& b) {
        bears.push_back(b);
    }

    // Tim kiem bear theo maBear
    void TimKiemBear(const string& maBear) const {
        bool found = false;
        for (const auto& bear : bears) {
            if (bear.getMaBear() == maBear) {
                cout << "***Tim thay bear :\n" << bear << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "***Khong tim thay bear co ma: " << maBear << endl;
        }
    }

    // Tinh toan max, min cho gia tri donGia
    void MaxMin() const {
        if (bears.empty()) return;
        auto maxBear = *max_element(bears.begin(), bears.end(), [](const Bear& a, const Bear& b) {
            return a.getDonGia() < b.getDonGia();
        });
        auto minBear = *min_element(bears.begin(), bears.end(), [](const Bear& a, const Bear& b) {
            return a.getDonGia() < b.getDonGia();
        });
        cout << "***Bear co don gia cao nhat:\n" << maxBear << endl;
        cout << "***Bear co don gia thap nhat:\n" << minBear << endl;
    }

    // Xoa bear theo maBear
    void XoaBear(const string& maBear) {
        auto it = find_if(bears.begin(), bears.end(), [&maBear](const Bear& bear) {
            return bear.getMaBear() == maBear;
        });
        if (it != bears.end()) {
            bears.erase(it);
            cout << "***Xoa thanh cong!\n";
        } else {
            cout << "***Khong tim thay bear co ma nay!\n";
        }
    }

    // Sua thong tin bear theo maBear
    void SuaBear(const string& maBear) {
        bool found = false;
        for (auto& bear : bears) {
            if (bear.getMaBear() == maBear) {
                cout << "***Nhap thong tin moi cho bear co ma " << maBear << ":\n";
                cin >> bear;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "***Khong tim thay bear co ma nay !\n";
        }
    }

    // Ghi danh sach bear vao file
    void writeFile(const string &filename) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cout << "***Khong the tao hoac mo tep tin.\n";
            return;
        }
        for (const auto& bear : bears) {
            file << bear << "\n";
        }cout << "***Da luu vao trong file khohang.txt";
        file.close();
    }
};

