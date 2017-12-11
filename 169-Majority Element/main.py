# -*- coding: utf-8 -*-


class Solution(object):

    def majorityElement(self, nums):
        """
        complex Algorithms
        :param nums:
        :return:
        """
        s = dict()
        size = len(nums)
        for num in nums:
            key = '%s' % num
            cur = 0
            if key in s:
                cur = s[key]
            s[key] = cur + 1
            if s[key] >= (size+1)/2:
                return num
        return 0

