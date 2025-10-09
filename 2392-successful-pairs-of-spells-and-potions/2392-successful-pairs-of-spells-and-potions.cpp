class Solution
{
public:
    using i64 = int64_t;
    [[nodiscard]] static constexpr std::vector<int> successfulPairs(
        std::vector<int>& spells,
        std::vector<int>& potions,
        i64 success) noexcept
    {
        std::ranges::sort(potions);
        for (int& spell : spells)
        {
            auto target = success / spell + ((success % spell) != 0);
            auto it = std::ranges::lower_bound(potions, target);
            spell = static_cast<int>(std::distance(it, potions.end()));
        }

        return std::move(spells);
    }
};