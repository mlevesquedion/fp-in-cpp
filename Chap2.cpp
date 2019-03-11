#include <vector>
#include <numeric>

using namespace std;

template<typename Combinator, typename Transformer, typename A, typename B>
B reduce_monoid(vector<A> &items, Combinator combine, Transformer transform, B identity) {
    return accumulate(
            items.begin(),
            items.end(),
            identity,
            [&](B acc, A next) {
                return combine(acc, transform(next));
            }
    );
}


template<typename T, typename Predicate>
bool any(vector<T> &items, Predicate predicate) {
    return reduce_monoid(items, [&](T a, T b) { return a || b; }, predicate, false);
}

template<typename T, typename Predicate>
bool all(vector<T> &items, Predicate predicate) {
    return reduce_monoid(items, [&](T a, T b) { return a && b; }, predicate, true);
}

