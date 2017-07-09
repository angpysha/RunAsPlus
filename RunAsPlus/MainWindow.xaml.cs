using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Logon;
using RunAsPlusLib;

namespace RunAsPlus
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            string user = textBox.Text;
            string pass = textBox_Copy.Text;
            string domain = textBox_Copy1.Text;
            string prog = textBox_Copy2.Text;
            string args = textBox_Copy3.Text;

            /*Dictionary<Logon.MPData, string> data = new Dictionary<MPData, string>
            {
                {MPData.user, user},
                {MPData.password,pass},
                {MPData.domain, domain },
                {MPData.processName, prog },
                {MPData.commandLineArgs, args },
                {MPData.type, "0" }
            };

            RunAsPlusLib.ProcessRunner runner = new ProcessRunner();
            runner.RunAsUser(data);*/
        }
    }
}
