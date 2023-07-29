#include <iostream>
#include <vector>
#include <unordered_set>

class Animal {
public:
    int number;
    int happy;
    int affect;
    Animal* left;
    Animal* right;

    Animal(int n, int h, int a) : number(n), happy(h), affect(a), left(nullptr), right(nullptr) {}
};

class Main {
public:
    int n; // Number of animals
    int m; // Number of operations
    std::vector<std::vector<int> > operate; // Operations content
    std::vector<int> result; // Operation results
    std::vector<Animal> animals; // Animal storage index
    std::vector<std::unordered_set<Animal*> > list; // Stores each circle

    Main() {
        std::cin >> n;
        animals.resize(n);
        for (int i = 0; i < n; i++) {
            int h, a;
            std::cin >> h >> a;
            animals[i] = Animal(i + 1, h, a);
        }
        animals[0].left = &animals[n - 1];
        animals[0].right = &animals[1];
        animals[n - 1].left = &animals[n - 2];
        animals[n - 1].right = &animals[0];
        for (int i = 1; i < n - 1; i++) {
            animals[i].left = &animals[i - 1];
            animals[i].right = &animals[i + 1];
        }
        std::cin >> m;
        operate.resize(m, std::vector<int>(3));
        for (int i = 0; i < m; i++) {
            std::cin >> operate[i][0] >> operate[i][1] >> operate[i][2];
        }
        result.resize(m, 0);
        list.push_back(createSet(&animals[0])); // Initially add a complete circle
        for (int i = 0; i < m; i++) {
            change(operate[i]);
            for (size_t j = 0; j < list.size(); j++) {
                result[i] += getEnergySum(list[j]);
            }
        }
        for (int a : result) {
            std::cout << a << std::endl;
        }
    }

    std::unordered_set<Animal*> createSet(Animal* animal) {
        std::unordered_set<Animal*> set;
        while (set.find(animal) == set.end()) {
            set.insert(animal);
            animal = animal->right;
        }
        return set;
    }

    void change(const std::vector<int>& once) {
        if (once[0] == 1) {
            divide(once[1] - 1, once[2] - 1);
        } else if (once[0] == 2) {
            animals[once[1] - 1].happy = once[2];
        } else if (once[0] == 3) {
            animals[once[1] - 1].affect = once[2];
        }
    }

    void divide(int i, int j) {
        bool sign = false;
        for (size_t a = 0; a < list.size(); a++) {
            if (list[a].find(&animals[i]) != list[a].end()) {
                if (list[a].find(&animals[j]) != list[a].end()) {
                    if (i + 1 == j) {
                        return;
                    }
                    sign = true;
                    list.erase(list.begin() + a);
                    a--;
                    break;
                } else {
                    sign = false;
                    list.erase(list.begin() + a);
                    a--;
                    continue;
                }
            }
            if (list[a].find(&animals[j]) != list[a].end()) {
                list.erase(list.begin() + a);
                a--;
            }
        }

        if (sign) {
            animals[i].right->left = animals[j].left;
            animals[j].left->right = animals[i].right;
            list.push_back(createSet(animals[i].right));
            animals[i].right = &animals[j];
            animals[j].left = &animals[i];
            list.push_back(createSet(&animals[i]));
        } else {
            animals[i].right->left = animals[j].left;
            animals[j].left->right = animals[i].right;
            animals[i].right = &animals[j];
            animals[j].left = &animals[i];
            list.push_back(createSet(&animals[i]));
        }
    }

    int getEnergySum(const std::unordered_set<Animal*>& set) {
        int sum = 0;
        for (const auto& headAnimal : set) {
            int headnumber = headAnimal->number;
            int p = 0;
            Animal* nextAnimal = headAnimal->right;
            while (nextAnimal->number != headnumber) {
                p++;
                sum += (p * nextAnimal->happy * headAnimal->affect);
                nextAnimal = nextAnimal->right;
            }
        }
        return sum;
    }
};

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    Main mainObj;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
