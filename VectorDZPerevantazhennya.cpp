#include <iostream>
using namespace std;

class Vector2D {
    int* x;
    int* y;
public:
    Vector2D() {
        x = 0;
        y = 0;
    }
    Vector2D(int x, int y) {
        this->x = &x;
        this->y = &y;
    }
    Vector2D(Vector2D& v) {
        this->x = v.x;
        this->y = v.y;
    }
    Vector2D(Vector2D&& v) : x(v.x), y(v.x) {
        x = new int;
        y = new int;
        v.x = nullptr;
        v.y = nullptr;
    }
    int GetX() {
        return *x;
    }
    int GetY() {
        return *y;
    }

    void SetX(int x) {
        this->x = &x;
    }
    void SetY(int y) {
        this->y = &y;
    }

    Vector2D operator+(Vector2D& v) {
        return Vector2D(this->GetX() + v.GetX(), this->GetY() + v.GetY());
    }

    Vector2D operator-(Vector2D& v) {
        return Vector2D(this->GetX() - v.GetX(), this->GetY() - v.GetY());
    }

    double Length() {
        return sqrt(this->GetX() ^ 2 + this->GetX() ^ 2);
    }
};

class Vector3D : public Vector2D {
    int* z;
public:
    Vector3D() {
        z = 0;
    }
    Vector3D(int x, int y, int z) : Vector2D(x, y) {
        this->z = &z;
    }
    Vector3D(Vector3D& v) : Vector2D(v) {
        this->z = v.z;
    }
    Vector3D(Vector3D&& v) : Vector2D(v.GetX(), v.GetY()) {
        z = new int;
        v.z = nullptr;
    }
    int GetZ() {
        return *z;
    }
    void SetZ(int z) {
        this->z = &z;
    }

    Vector3D operator+(Vector3D& v) {
        this->SetX(this->GetX() + v.GetX());
        this->SetY(this->GetY() + v.GetY());
        this->SetZ(this->GetZ() + v.GetZ());
        return *this;
    }

    Vector3D operator-(Vector3D& v) {
        this->SetX(this->GetX() - v.GetX());
        this->SetY(this->GetY() - v.GetY());
        this->SetZ(this->GetZ() - v.GetZ());
        return *this;
    }
    Vector3D operator++() {
        this->SetX(this->GetX() + 1);
        this->SetY(this->GetY() + 1);
        this->SetZ(this->GetZ() + 1);
        return *this;
    }
    Vector3D operator--() {
        this->SetX(this->GetX() - 1);
        this->SetY(this->GetY() - 1);
        this->SetZ(this->GetZ() - 1);
        return *this;
    }
    Vector3D operator++(int) {
        Vector3D t = *this;
        this->SetX(this->GetX() + 1);
        this->SetY(this->GetY() + 1);
        this->SetZ(this->GetZ() + 1);
        return t;
    }
    Vector3D operator--(int) {
        Vector3D t = *this;
        this->SetX(this->GetX() - 1);
        this->SetY(this->GetY() - 1);
        this->SetZ(this->GetZ() - 1);
        return t;
    }

    bool operator>(Vector3D& v) {
        if (this->GetX() > v.GetX() && this->GetY() > v.GetY() && this->GetZ() > v.GetZ()) {
            return true;
        }
        else return false;
    }
    bool operator<(Vector3D& v) {
        if (this->GetX() < v.GetX() && this->GetY() < v.GetY() && this->GetZ() < v.GetZ()) {
            return true;
        }
        else return false;
    }
    bool operator>=(Vector3D& v) {
        if (this->GetX() >= v.GetX() && this->GetY() >= v.GetY() && this->GetZ() >= v.GetZ()) {
            return true;
        }
        else return false;
    }
    bool operator<=(Vector3D& v) {
        if (this->GetX() <= v.GetX() && this->GetY() <= v.GetY() && this->GetZ() <= v.GetZ()) {
            return true;
        }
        else return false;
    }
    bool operator==(Vector3D& v) {
        if (this->GetX() == v.GetX() && this->GetY() == v.GetY() && this->GetZ() == v.GetZ()) {
            return true;
        }
        else return false;
    }

    void operator=(Vector3D& v) {
        this->SetX(v.GetX());
        this->SetY(v.GetY());
        this->SetZ(v.GetZ());
    }

    double Length() {
        return sqrt(this->GetX() ^ 2 + this->GetY() ^ 2 + this->GetZ() ^ 2);
    }

    bool operator==(Vector2D& v) {
        if (this->Length() == v.Length()) return true;
        else return false;
    }
};

ostream& operator<<(ostream& os, Vector3D& v) {
    return os << "x: " << v.GetX() << " Y: " << v.GetY() << " Z: " << v.GetZ();
}

int main() {
    Vector3D v1 = Vector3D(6, 10, 8);
    Vector3D v2 = Vector3D(7, 6, 7);

    Vector3D v3 = v1 + v2;
    cout << v3 << endl;

    Vector3D v4 = v1 - v2;
    cout << v4 << endl;

    Vector3D v5 = v1++;
    cout << v5 << endl;

    Vector3D v6 = v1--;
    cout << v6 << endl;

    Vector3D v7 = ++v1;
    cout << v7 << endl;

    Vector3D v8 = --v1;
    cout << v8 << endl;


}
