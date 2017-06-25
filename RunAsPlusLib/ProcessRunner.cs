using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Logon;
using MLogon;

namespace RunAsPlusLib
{
    public class ProcessRunner
    {
        public ProcessRunner()
        {
            
        }

        ~ProcessRunner()
        {
            
        }

        public bool RunAsUser(Dictionary<MPData, string> data)
        {
           // LogonHelper helper = new Logon.LogonHelper();
           // helper.runAsAnotherUser(data);
          //  return helper.runAsAnotherUser(data);
            return false;
        }

        public static void MessageBoxX(string str)
        {
            LogonHelper helper = new LogonHelper();

            helper.MsgBx(str);
        }
    }
}
