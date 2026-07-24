#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

// 1. Lớp cơ sở Shape (Abstract Class)
class Shape {
public:
    virtual string getName() const = 0; // Hàm thuần ảo
    virtual ~Shape() {} // Destructor ảo để đảm bảo giải phóng bộ nhớ an toàn
};

// 2. Lớp trung gian Shape2D (Abstract Class)
class Shape2D : public Shape {
public:
    virtual double getArea() const = 0;      // Hàm thuần ảo diện tích
    virtual double getPerimeter() const = 0; // Hàm thuần ảo chu vi
};

// 3. Lớp Circle kế thừa Shape2D (Concrete Class)
class Circle : public Shape2D {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    string getName() const override {
        return "Circle (Hinh Tron)";
    }

    double getArea() const override {
        return PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * PI * radius;
    }
};

// 4. Lớp trung gian Shape3D (Abstract Class)
class Shape3D : public Shape {
public:
    virtual double getVolume() const = 0;      // Hàm thuần ảo thể tích
    virtual double getSurfaceArea() const = 0; // Hàm thuần ảo diện tích toàn phần
};

// 5. Lớp Sphere kế thừa Shape3D (Concrete Class)
class Sphere : public Shape3D {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    string getName() const override {
        return "Sphere (Hinh Cau)";
    }

    double getVolume() const override {
        return (4.0 / 3.0) * PI * std::pow(radius, 3);
    }

    double getSurfaceArea() const override {
        return 4.0 * PI * radius * radius;
    }
};

int main() {
    cout << fixed << setprecision(2);

    // Tạo đối tượng Circle và Sphere
    Circle circle(5.0);
    Sphere sphere(3.0);

    // Sử dụng thông qua con trỏ Lớp cơ sở để thể hiện tính đa hình
    Shape2D* s2d = &circle;
    cout << "=== " << s2d->getName() << " ===" << endl;
    cout << "Dien tich: " << s2d->getArea() << endl;
    cout << "Chu vi: " << s2d->getPerimeter() << endl;

    cout << endl;

    Shape3D* s3d = &sphere;
    cout << "=== " << s3d->getName() << " ===" << endl;
    cout << "The tich: " << s3d->getVolume() << endl;
    cout << "Dien tich toan phan: " << s3d->getSurfaceArea() << endl;

    // LƯU Ý VỀ NGÓC NGÁCH CẦN XỬ LÝ:
    // Nếu bạn bỏ comment các dòng dưới đây, compiler sẽ báo lỗi ngay vì Shape, Shape2D, Shape3D đều là Abstract Class:
    // Shape s;       // Error!
    // Shape2D s2;    // Error!
    // Shape3D s3;    // Error!

    return 0;
}