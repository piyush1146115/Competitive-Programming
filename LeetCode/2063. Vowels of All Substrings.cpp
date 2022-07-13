class Solution {
public:
bool v[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
long long countVowels(string w) {
    long long res = 0, sz = w.size();
    for (int i = 0; i < w.size(); ++i)
        res += v[w[i] - 'a'] * (i + 1) * (sz - i);
    return res;
}
};

