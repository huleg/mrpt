/* +---------------------------------------------------------------------------+
   |                 The Mobile Robot Programming Toolkit (MRPT)               |
   |                                                                           |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2013, Individual contributors, see AUTHORS file        |
   | Copyright (c) 2005-2013, MAPIR group, University of Malaga                |
   | Copyright (c) 2012-2013, University of Almeria                            |
   | All rights reserved.                                                      |
   |                                                                           |
   | Redistribution and use in source and binary forms, with or without        |
   | modification, are permitted provided that the following conditions are    |
   | met:                                                                      |
   |    * Redistributions of source code must retain the above copyright       |
   |      notice, this list of conditions and the following disclaimer.        |
   |    * Redistributions in binary form must reproduce the above copyright    |
   |      notice, this list of conditions and the following disclaimer in the  |
   |      documentation and/or other materials provided with the distribution. |
   |    * Neither the name of the copyright holders nor the                    |
   |      names of its contributors may be used to endorse or promote products |
   |      derived from this software without specific prior written permission.|
   |                                                                           |
   | THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       |
   | 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED |
   | TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR|
   | PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE |
   | FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL|
   | DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR|
   |  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)       |
   | HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,       |
   | STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  |
   | ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           |
   | POSSIBILITY OF SUCH DAMAGE.                                               |
   +---------------------------------------------------------------------------+ */

/*  Plane-based Map (PbMap) library
 *  Construction of plane-based maps and localization in it from RGBD Images.
 *  Writen by Eduardo Fernandez-Moral. See docs for <a href="group__mrpt__pbmap__grp.html" >mrpt-pbmap</a>
 */
#include <mrpt/pbmap.h> // precomp. hdr

using namespace std;

void printHelp()
{
    std::cout<<"---------------------------------------------------------------------------------------"<< std::endl;
    std::cout<<"./PbMapVisualizer <pointCloud.pcd> <MapPlanes.xml>" << std::endl;
    std::cout<<"       options: " << std::endl;
    std::cout<<"         -p | P: Show/hide point cloud" << std::endl;
    std::cout<<"         -l | L: Show/hide PbMap" << std::endl;
    std::cout<<"         -r | R: Switch between point cloud and graph representation" << std::endl;
};


int main(int argc, char** argv)
{
//  for(unsigned i=0; i<argc; i++)
//    cout << static_cast<string>(argv[i]) << endl;

  if(argc != 3)
  {
    printHelp();
    return -1;
  }

//  string pointCloudFile = "/home/edu/Projects/PbMaps/" + static_cast<string>(argv[1]) + "/MapPlanes.pcd";
//  string PbMapFile = "/home/edu/Projects/PbMaps/" + static_cast<string>(argv[1]) + "/MapPlanes.xml";
  string pointCloudFile = string(argv[1]);
  string PbMapFile = string(argv[2]);

  PbMapVisualizer mapViewer;

  if( !mapViewer.loadPlaneMap(pointCloudFile, PbMapFile) )
    cerr << "viewMapPlane cannot load the map\n";

  mapViewer.Run();

  return 0;
}