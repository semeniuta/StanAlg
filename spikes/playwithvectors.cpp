#include <iostream>
#include <vector>

using namespace std;

class VectorContainer {

  public:
    VectorContainer(vector<int>* v);
    void setVal(int index, int val);
    void pushBack(int val);

  private:
    vector<int>* pvec;

};


VectorContainer::VectorContainer(vector<int>* v) {
  this->pvec = v;
}

void VectorContainer::setVal(int index, int val) {
  if (index < 0 || index > pvec->size()) {
    return;
  }

  (*(this->pvec))[index] = val;

  for (int i = 0; i < this->pvec->size(); i++) {
    cout << (*(this->pvec))[i] << " ";
  }
  cout << endl;
}

void VectorContainer::pushBack(int val) {
  (this->pvec)->push_back(val);
}

int main() {
  vector<int> a = {4, 6, 2, 7, 1};

  VectorContainer vc(&a);

  vc.setVal(0, 0);
  vc.setVal(1, 0);
  vc.pushBack(200);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
