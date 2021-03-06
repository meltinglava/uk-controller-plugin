#pragma once
#include "tag/TagItemInterface.h"
#include "datablock/DisplayTime.h"
#include "tag/TagData.h"

namespace UKControllerPlugin {
    namespace Euroscope {
        class EuroScopeCFlightPlanInterface;
        class EuroScopeCRadarTargetInterface;
    }  // namespace Euroscope
    namespace Flightplan {
        class StoredFlightplanCollection;
    }  // namespace Flightplan
}  // namespace UKControllerPlugin

namespace UKControllerPlugin {
namespace Datablock {

class EstimatedOffBlockTimeEventHandler : public UKControllerPlugin::Tag::TagItemInterface
{
    public:
        EstimatedOffBlockTimeEventHandler(
            const UKControllerPlugin::Flightplan::StoredFlightplanCollection & storedFlightplans,
            const UKControllerPlugin::Datablock::DisplayTime & displayTime
        );
        std::string GetTagItemDescription(int tagItemId) const override;
        void SetTagItemData(UKControllerPlugin::Tag::TagData& tagData) override;

    private:

        // Stored flightplans
        const UKControllerPlugin::Flightplan::StoredFlightplanCollection & storedFlightplans;

        // Class for converting timestamps to display times and getting the no time format
        const UKControllerPlugin::Datablock::DisplayTime & displayTime;
};
}  // namespace Datablock
}  // namespace UKControllerPlugin
