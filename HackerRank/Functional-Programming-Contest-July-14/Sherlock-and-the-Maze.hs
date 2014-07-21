import Control.Monad
import Data.Array

main = do
	strN <- getLine
	content <- getContents
	putStrLn $ unlines $ map (\line -> readAndProcessLine dp line) $ lines content
	where dp = solveDP 100 100 100

readAndProcessLine ::  Array Int (Array Int (Array Int (Array Int Int))) -> String -> String
readAndProcessLine dp line = show $ (\[n, m, k] -> solve n m k dp) $ map (\value -> read value::Int) $ words line 

solve :: Int -> Int -> Int -> Array Int (Array Int (Array Int (Array Int Int))) -> Int
solve 1 1 _ dp = 1
solve n m k dp = foldl (\a x-> mod (a+x) 1000000007) 0 [dp!n!m!x!y | x<-[0..k], y<-[0..1]]

solveDP :: Int -> Int -> Int -> Array Int (Array Int (Array Int (Array Int Int)))
solveDP n m k = let
	res = array (1,n) [
		(i, array (1,m) [
			(j, array (0,k) [
				(q,array (0,1) [(d,val i j q d) | d<-[0,1] ])
				| q<-[0..k] ]) 
			| j<-[1..m] ]) 
		| i<-[1..n]]
	val i j q d = case (i,j,q,d) of
		(1,1,0,_) -> 1
		(1,j,0,0) -> 1
		(1,_,_,_) -> 0
		(i,1,0,1) -> 1
		(i,1,_,_) -> 0
		(i,j,0,0) -> res!i!(j-1)!0!0
		(i,j,0,1) -> res!(i-1)!j!0!1
		(i,j,q,0) -> mod (res!i!(j-1)!q!0 + res!i!(j-1)!(q-1)!1) 1000000007
		(i,j,q,1) -> mod (res!(i-1)!j!(q-1)!0 + res!(i-1)!j!q!1) 1000000007
	in res
