void runData()
{
 std::vector<std::string> paths;
 paths.push_back("../TBJPETRun2/2021.06.28_0001"); 
 paths.push_back("../TBJPETRun2/2021.06.28_0002"); 
 paths.push_back("../TBJPETRun2/2021.06.28_0003"); 
 paths.push_back("../TBJPETRun2/2021.06.28_0004"); 
 paths.push_back("../TBJPETRun2/2021.06.28_0005"); 
 paths.push_back("../TBJPETRun2/2021.06.29_0001"); 
 paths.push_back("../TBJPETRun2/2021.06.29_0002"); 
 paths.push_back("../TBJPETRun2/2021.06.29_0003"); 
 paths.push_back("../TBJPETRun2/2021.06.29_0004"); 
 paths.push_back("../TBJPETRun2/2021.06.29_0005"); 
 paths.push_back("../TBJPETRun2/2021.06.30_0001"); 
 paths.push_back("../TBJPETRun2/2021.06.30_0002"); 
 paths.push_back("../TBJPETRun2/2021.06.30_0003"); 
 paths.push_back("../TBJPETRun2/2021.06.30_0005"); 
 for(int i = 0; i < paths.size(); i++)
   SignalExtraction( paths[i] );
}
