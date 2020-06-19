impl Solution
{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut res = Vec::new();
        let n = nums.len();
        'outer: for i in 0..n
        {
            for j in 0..i
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push(j as i32);
                    res.push(i as i32);
                    break 'outer;
                }
            }
        }

        return res;
    }
}
