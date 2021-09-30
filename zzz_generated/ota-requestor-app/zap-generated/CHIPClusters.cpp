/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include "CHIPClusters.h"

#include <cstdint>

#include <app-common/zap-generated/ids/Attributes.h>
#include <app/InteractionModelEngine.h>
#include <app/chip-zcl-zpro-codec.h>
#include <app/util/basic-types.h>
#include <lib/support/BufferWriter.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/SafeInt.h>
#include <lib/support/logging/CHIPLogging.h>
#include <system/SystemPacketBuffer.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

using namespace app::Clusters;
using namespace System;
using namespace Encoding::LittleEndian;

namespace Controller {

// TODO(#4502): onCompletion is not used by IM for now.
// TODO(#4503): length should be passed to commands when byte string is in argument list.
// TODO(#4503): Commands should take group id as an argument.

// OtaSoftwareUpdateProvider Cluster Commands
CHIP_ERROR OtaSoftwareUpdateProviderCluster::ApplyUpdateRequest(Callback::Cancelable * onSuccessCallback,
                                                                Callback::Cancelable * onFailureCallback,
                                                                chip::ByteSpan updateToken, uint32_t newVersion)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OtaSoftwareUpdateProvider::Commands::ApplyUpdateRequest::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // updateToken: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), updateToken));
    // newVersion: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), newVersion));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OtaSoftwareUpdateProviderCluster::NotifyUpdateApplied(Callback::Cancelable * onSuccessCallback,
                                                                 Callback::Cancelable * onFailureCallback,
                                                                 chip::ByteSpan updateToken, uint32_t softwareVersion)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OtaSoftwareUpdateProvider::Commands::NotifyUpdateApplied::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // updateToken: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), updateToken));
    // softwareVersion: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), softwareVersion));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

CHIP_ERROR OtaSoftwareUpdateProviderCluster::QueryImage(Callback::Cancelable * onSuccessCallback,
                                                        Callback::Cancelable * onFailureCallback, uint16_t vendorId,
                                                        uint16_t productId, uint16_t hardwareVersion, uint32_t softwareVersion,
                                                        uint8_t protocolsSupported, chip::ByteSpan location,
                                                        bool requestorCanConsent, chip::ByteSpan metadataForProvider)
{
    CHIP_ERROR err              = CHIP_NO_ERROR;
    app::CommandSender * sender = nullptr;
    TLV::TLVWriter * writer     = nullptr;
    uint8_t argSeqNumber        = 0;

    // Used when encoding non-empty command. Suppress error message when encoding empty commands.
    (void) writer;
    (void) argSeqNumber;

    VerifyOrReturnError(mDevice != nullptr, CHIP_ERROR_INCORRECT_STATE);

    app::CommandPathParams cmdParams = { mEndpoint, /* group id */ 0, mClusterId,
                                         OtaSoftwareUpdateProvider::Commands::QueryImage::Id,
                                         (app::CommandPathFlags::kEndpointIdValid) };

    SuccessOrExit(err = app::InteractionModelEngine::GetInstance()->NewCommandSender(&sender));

    SuccessOrExit(err = sender->PrepareCommand(cmdParams));

    VerifyOrExit((writer = sender->GetCommandDataElementTLVWriter()) != nullptr, err = CHIP_ERROR_INCORRECT_STATE);
    // vendorId: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), vendorId));
    // productId: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), productId));
    // hardwareVersion: int16u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), hardwareVersion));
    // softwareVersion: int32u
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), softwareVersion));
    // protocolsSupported: oTADownloadProtocol
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), protocolsSupported));
    // location: charString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), location));
    // requestorCanConsent: boolean
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), requestorCanConsent));
    // metadataForProvider: octetString
    SuccessOrExit(err = writer->Put(TLV::ContextTag(argSeqNumber++), metadataForProvider));

    SuccessOrExit(err = sender->FinishCommand());

    // #6308: This is a temporary solution before we fully support IM on application side and should be replaced by IMDelegate.
    mDevice->AddIMResponseHandler(sender, onSuccessCallback, onFailureCallback);

    err = mDevice->SendCommands(sender);

exit:
    // On error, we are responsible to close the sender.
    if (err != CHIP_NO_ERROR && sender != nullptr)
    {
        sender->Shutdown();
    }
    return err;
}

// OtaSoftwareUpdateProvider Cluster Attributes
CHIP_ERROR OtaSoftwareUpdateProviderCluster::ReadAttributeClusterRevision(Callback::Cancelable * onSuccessCallback,
                                                                          Callback::Cancelable * onFailureCallback)
{
    app::AttributePathParams attributePath;
    attributePath.mEndpointId = mEndpoint;
    attributePath.mClusterId  = mClusterId;
    attributePath.mFieldId    = 0x0000FFFD;
    attributePath.mFlags.Set(app::AttributePathParams::Flags::kFieldIdValid);
    return mDevice->SendReadAttributeRequest(attributePath, onSuccessCallback, onFailureCallback,
                                             BasicAttributeFilter<Int16uAttributeCallback>);
}

} // namespace Controller
} // namespace chip
