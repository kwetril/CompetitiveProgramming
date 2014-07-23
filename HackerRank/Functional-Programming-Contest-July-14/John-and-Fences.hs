import Data.Array
import Data.List

groupBy' :: (a -> a -> Bool) -> [a] -> [[a]]
groupBy' _   []                        = []
groupBy' _   [x]                       = [[x]]
groupBy' cmp (x:xs@(x':_)) | cmp x x'  = (x:y):ys
                           | otherwise = [x]:r
  where r@(y:ys) = groupBy' cmp xs

main = do
	strN <- getLine
	strList <- getLine
	putStrLn $ show $ solve $ map (\ x -> read x::Int) $ words $ strList
	
solve :: [Int] -> Int
solve list = solveRecursive 1 len a
	where 
		len = length list
		a = listArray (1,len) list

solveRecursive :: Int -> Int -> Array Int Int -> Int
solveRecursive left right a = if left==right 
	then a!left
	else let
		m = minimum [a!i | i <- [left..right]]
		rs = map (\ list -> (fst $ head list,fst $ last list ) ) $ groupBy' (\ (i,x) (j,y) -> i+1==j) $ filter (\ (i,v) -> v>m) [(i,a!i) | i <- [left..right]]
		in maximum $ ((right-left+1)*m) : [solveRecursive x y a | (x,y) <- rs]

