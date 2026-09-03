class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        nums1.sort()
        odd = True
        even = True
        for i in nums1:
            if i&1:
                even = False
            else:
                odd = False

        if not even and not nums1[0]&1:
            return False
        return True


        # o e