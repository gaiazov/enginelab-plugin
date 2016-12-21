using System;

namespace ELPlugin
{
    public class Implementation
    {
        public static string GetPlugInName()
        {
            return "EL C# Plugin";
        }

        public static void TargetConnected(ELTargetWrapper target)
        {
            var targetName = target.GetName();
            Console.WriteLine($"Target = {targetName}");

            if (target.InterfaceVersion() < 3) return;

            var model = target.Modeler();

            Console.WriteLine(model.NextAvailableChannelNumber());
        }
    }
}
