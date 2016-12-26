using System;

namespace ELPlugin
{
    public class Implementation
    {
        private static ELModelWrapper _model;
        private static ELGenericInfoListWrapper _itemTypes;
        private static ELGenericInfoListWrapper _thermistorTypes;

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

            _itemTypes = target.InfoList((uint)Constants.TargetType.ITEM_TYPES);
            _thermistorTypes = target.InfoList((uint)Constants.TargetType.THERMISTOR_OUTPUT_TYPES);
        }

        public static void MenuClicked(uint menuId)
        {
            var item = _model.NewItem("Test", _itemTypes.Info((uint)Constants.ItemType.THERMISTOR));

            item.AddConstantChannel(0, 1234);
            item.AddConstantChannel(1, 2490);

            // todo: set thermistor output type
            var thermistorType = _thermistorTypes.Info((uint)Constants.ThermistorOutputType.CLT_1GDSM_DEGC);

            var status = (Constants.Status)_model.CreateItem(item);
            Console.WriteLine(status);
        }
    }
}
