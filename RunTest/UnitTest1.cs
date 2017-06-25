using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RunTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
        }

        [TestMethod]
        public void StartProgram()
        {
            
        }

        [TestMethod]
        public void MsbBOXX()
        {
            RunAsPlusLib.ProcessRunner.MessageBoxX("HAHAHAHAH");
        }
        [TestMethod]
        public void mmsfd()
        {
           Testing fds = new Testing();
            fds.tstMsg("хаафыв");
        }

        [TestMethod]
        public void mmsfd2()
        {
            Testing fds = new Testing();
            string ff = "0";
            string z;
            fds.tstMsgg(ff, out z);
            RunAsPlusLib.ProcessRunner.MessageBoxX(z);
        }
    }
}
