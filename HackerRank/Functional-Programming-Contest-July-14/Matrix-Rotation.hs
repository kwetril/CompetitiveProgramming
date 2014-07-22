import Data.Array

main = do
	content <- getContents
	putStrLn $ processInput $ (map.map) (\ x -> read x::Int) $ map words $ lines content

processInput :: [[Int]] -> String 
processInput list = let
	[n,m,r] = head list
	a = array (1,n) $ zip [1..n] $ map (\ x -> array (1,m) $ zip [1..m] x) $ tail list
	in
	showArray n m $ solve n m r a

solve :: Int -> Int -> Int -> Array Int (Array Int Int) -> Array Int (Array Int Int)
solve n m r a = combineLists n m $ map (rotateList r) $ splitToLists a n m 0 

splitToLists :: Array Int (Array Int Int) -> Int -> Int -> Int -> [[Int]]
splitToLists a n m level = if level*2 == n || level*2 == m 
	then [] 
	else concat [
		[a!i!(1+level) | i<-[1+level..n-level-1] ], 
		[a!(n-level)!i | i<-[1+level..m-level-1] ], 
		[a!i!(m-level) | i<-[n-level, n-level-1 .. 2+level] ], 
		[a!(1+level)!i | i<-[m-level, m-level-1 .. 2+level] ] 
	] : splitToLists a n m (level+1)

rotateList :: Int -> [Int] -> [Int]
rotateList r list = let
	n = length list
	m = n - mod r n
	in take n $ drop m $ cycle list

combineLists :: Int -> Int -> [[Int]] -> Array Int (Array Int Int)
combineLists n m lists = let 
	tmpA = array (0,(length lists) - 1) $ zip [0..] $ map (\ x -> array (0,(length x) - 1) $ zip [0..] x) $ lists
	val i j = let
		level = minimum [i-1,j-1,n-i,m-j]
		inRange x a b = a <= x && x <= b
		pos = case (i,j,level) of
			_	| 1 + level == j && inRange i (1+level) (n-level-1) -> i - level - 1
				| n - level == i && inRange j (1+level) (m-level-1) -> (n - 2 * level - 1) + j - level - 1
				| m - level == j && inRange i (2+level) (n-level) -> (n - 2 * level - 1) + (m - 2 * level-1) + n - level - i
				| 1 + level == i && inRange j (2+level) (m-level) -> 2 * (n - 2 * level - 1) + (m - 2 * level - 1) + m - level - j
		in tmpA!level!pos
	in array (1,n) [(i, array (1,m) [(j, val i j) | j <- [1..m]]) | i <- [1..n]]
	
showArray :: Int -> Int -> Array Int (Array Int Int) -> String
showArray n m a = unlines $ map unwords $ (map.map) show [[a!i!j | j<-[1..m]] | i <- [1..n]]

