using System;

namespace ELPlugin
{
    public class Implementation
    {
        private static ELModelWrapper _model;
        private static ELGenericInfoListWrapper _itemTypes;

        public static string GetPlugInName()
        {
            return "EL C# Plugin";
        }

        public static void TargetConnected(ELTargetWrapper target)
        {
            var targetName = target.GetName();
            Console.WriteLine($"Target = {targetName}");

            if (target.InterfaceVersion() < 3) return;

            _model = target.Modeler();

            Console.WriteLine(_model.NextAvailableChannelNumber());

            _itemTypes = target.InfoList(15); // TARGETINFO_ITEM_TYPES
        }

        public static void MenuClicked(uint menuId)
        {
            var type = _itemTypes.InfoItemType(0); // ITEMTYPE_NONE
            var item = _model.CreateNoop("Test", type);
        }
    }
}
