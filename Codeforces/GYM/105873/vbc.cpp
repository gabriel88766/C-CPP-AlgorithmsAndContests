#include <bits/stdc++.h>
using namespace std;

double randf(double a, double b) {
    return a + (b - a) * (double(rand()) / RAND_MAX);
}

double tanh_act(double x) {
    return tanh(x);
}

struct Individual {
    int input_size;
    int hidden_size;
    int output_size;

    vector<vector<double>> W1;
    vector<double> b1;

    vector<vector<double>> W2;
    vector<double> b2;

    double fitness = 0.0;

    Individual(int in, int hid, int out)
        : input_size(in), hidden_size(hid), output_size(out) {

        W1.resize(hidden_size, vector<double>(input_size));
        b1.resize(hidden_size);

        W2.resize(output_size, vector<double>(hidden_size));
        b2.resize(output_size);

        randomize();
    }

    void randomize() {
        for (auto &row : W1)
            for (auto &v : row) v = randf(-1, 1);
        for (auto &v : b1) v = randf(-1, 1);

        for (auto &row : W2)
            for (auto &v : row) v = randf(-1, 1);
        for (auto &v : b2) v = randf(-1, 1);
    }

    vector<double> forward(const vector<double>& x) const {
        vector<double> hidden(hidden_size);
        for (int i = 0; i < hidden_size; i++) {
            double sum = b1[i];
            for (int j = 0; j < input_size; j++)
                sum += W1[i][j] * x[j];
            hidden[i] = tanh_act(sum);
        }

        vector<double> out(output_size);
        for (int i = 0; i < output_size; i++) {
            double sum = b2[i];
            for (int j = 0; j < hidden_size; j++)
                sum += W2[i][j] * hidden[j];
            out[i] = sum;
        }
        return out;
    }

    void mutate(double rate = 0.1, double scale = 0.3) {
        auto mutate_val = [&](double &v) {
            if (randf(0, 1) < rate)
                v += randf(-scale, scale);
        };

        for (auto &row : W1)
            for (auto &v : row) mutate_val(v);
        for (auto &v : b1) mutate_val(v);

        for (auto &row : W2)
            for (auto &v : row) mutate_val(v);
        for (auto &v : b2) mutate_val(v);
    }
};

struct Population {
    vector<Individual> pop;
    int elite_count;

    Population(int size, int elite, int in, int hid, int out)
        : elite_count(elite) {
        for (int i = 0; i < size; i++)
            pop.emplace_back(in, hid, out);
    }

    template<typename Validator>
    void evaluate(Validator validator) {
        for (auto &ind : pop)
            ind.fitness = validator(ind);
    }

    void evolve() {
        sort(pop.begin(), pop.end(),
             [](const Individual &a, const Individual &b) {
                 return a.fitness > b.fitness;
             });

        vector<Individual> next;

        // Keep elites unchanged
        for (int i = 0; i < elite_count; i++)
            next.push_back(pop[i]);

        // Fill rest with mutated copies
        while ((int)next.size() < (int)pop.size()) {
            int parent = rand() % elite_count;
            Individual child = pop[parent];
            child.mutate();
            next.push_back(child);
        }

        pop = move(next);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double validator_example(const Individual &ind) {
    // Example: learn y = x0 + x1
    vector<vector<double>> inputs;
    vector<double> targets;
    for(int i=0;i<10;i++){
        double a = uniform_real_distribution<double>(0, 1)(rng);
        double b = uniform_real_distribution<double>(0, 1)(rng);
        inputs.push_back({a, b});
        targets.push_back(a*a+a*b+b*b);
    }

    double error = 0;
    for (int i = 0; i < inputs.size(); i++) {
        double y = ind.forward(inputs[i])[0];
        error += fabs(y - targets[i]);
    }

    return -error; // higher fitness = better
}

int main() {
    freopen("out", "w", stdout);
    srand(time(NULL));

    Population pop(
        200,    // population size
        50,     // elite count
        2,      // input
        8,      // hidden
        1       // output
    );

    for (int gen = 0; gen < 10000; gen++) {
        pop.evaluate(validator_example);
        pop.evolve();

        cout << "Gen " << gen
             << " best fitness: " << pop.pop[0].fitness << " ";
             vector<double> tst = {0.2, 0.8};
             double y = pop.pop[0].forward(tst)[0];
             cout << y << "\n";
    }
    
}
