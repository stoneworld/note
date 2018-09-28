<?php

// 归并排序 https://www.cnblogs.com/chengxiao/p/6194356.html
// 分而治之 先分后合

function mergeSort($arr) {
    $len = count($arr);
    if ($len <= 1) return $arr;
    $half = ceil($len/2);
    $arr2d = array_chunk($arr, $half);
    $left = mergeSort($arr2d[0]);
    $right = mergeSort($arr2d[1]);
    while(count($left) && count($right)) {
        if ($left[0]<$right[0]) {
            $reg[] = array_shift($left);
        } else {
            $reg[] = array_shift($right);
        }
    }
    return array_merge($reg, $left, $right);
}

$arr = array(21, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70);
$arr = mergeSort($arr);
print_r($arr);
