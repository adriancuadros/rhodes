require File.dirname(File.join(__rhoGetCurrentDir(), __FILE__)) + '/../../../../spec_helper'
require 'net/http'
require File.dirname(File.join(__rhoGetCurrentDir(), __FILE__)) + '/fixtures/http_server'

describe "Net::HTTP#mkcol" do
  before(:all) do
    NetHTTPSpecs.start_server
  end
  
  after(:all) do
    NetHTTPSpecs.stop_server
  end
  
  before(:each) do
    @http = Net::HTTP.start("localhost", 3333)
  end
  
  it "sends a MKCOL request to the passed path and returns the response" do
    response = @http.mkcol("/request")
    response.should be_kind_of(Net::HTTPResponse)
    response.body.should == "Request type: MKCOL"
  end
end