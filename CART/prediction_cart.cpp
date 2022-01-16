#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[2] <= 290.81100000000004) {
		if (features[346] <= 23.50675) {
			if (features[257] <= 179.733) {
				if (features[5] <= 25.9583) {
					if (features[0] <= 73.3401) {
						return ( "jazz");
					} else {
						return ( "classical");
					}
				} else {
					if (features[1] <= 139.6765) {
						return ( "classical");
					} else {
						if (features[0] <= 47.84715) {
							return ( "jazz");
						} else {
							return ( "classical");
						}
					}
				}
			} else {
				if (features[2] <= 196.3465) {
					if (features[0] <= 90.97945) {
						return ( "classical");
					} else {
						return ( "rock");
					}
				} else {
					return ( "jazz");
				}
			}
		} else {
			if (features[0] <= 219.9235) {
				if (features[59] <= 33.902550000000005) {
					if (features[286] <= 97.2262) {
						if (features[0] <= 20.96475) {
							return ( "reggae");
						} else {
							return ( "pop");
						}
					} else {
						return ( "jazz");
					}
				} else {
					if (features[9] <= 229.594) {
						return ( "rock");
					} else {
						if (features[14] <= 206.0575) {
							return ( "reggae");
						} else {
							if (features[1] <= 89.789) {
								if (features[0] <= 14.69035) {
									return ( "pop");
								} else {
									if (features[0] <= 33.624) {
										return ( "country");
									} else {
										return ( "blues");
									}
								}
							} else {
								return ( "classical");
							}
						}
					}
				}
			} else {
				return ( "blues");
			}
		}
	} else {
		if (features[244] <= 49.6482) {
			if (features[97] <= 78.35745) {
				if (features[258] <= 675.318) {
					if (features[4] <= 315.1635) {
						if (features[326] <= 60.3994) {
							if (features[318] <= 78.2481) {
								return ( "jazz");
							} else {
								if (features[0] <= 191.6999) {
									return ( "country");
								} else {
									return ( "pop");
								}
							}
						} else {
							if (features[0] <= 168.53) {
								if (features[0] <= 109.4369) {
									if (features[0] <= 40.93145) {
										return ( "hiphop");
									} else {
										if (features[0] <= 58.6794) {
											return ( "country");
										} else {
											return ( "metal");
										}
									}
								} else {
									return ( "reggae");
								}
							} else {
								return ( "blues");
							}
						}
					} else {
						if (features[151] <= 12.991150000000001) {
							if (features[461] <= 1.3052350000000001) {
								if (features[60] <= 47.5446) {
									return ( "jazz");
								} else {
									if (features[0] <= 58.1044) {
										return ( "rock");
									} else {
										return ( "blues");
									}
								}
							} else {
								if (features[280] <= 272.8045) {
									if (features[306] <= 16.887) {
										if (features[0] <= 77.15935) {
											return ( "blues");
										} else {
											return ( "rock");
										}
									} else {
										if (features[95] <= 38.464150000000004) {
											return ( "country");
										} else {
											if (features[0] <= 153.43) {
												return ( "classical");
											} else {
												return ( "jazz");
											}
										}
									}
								} else {
									if (features[38] <= 109.7005) {
										if (features[0] <= 229.87635) {
											return ( "blues");
										} else {
											return ( "country");
										}
									} else {
										return ( "jazz");
									}
								}
							}
						} else {
							if (features[268] <= 472.4175) {
								if (features[359] <= 23.36195) {
									if (features[6] <= 342.7595) {
										return ( "disco");
									} else {
										return ( "pop");
									}
								} else {
									if (features[264] <= 220.0895) {
										if (features[277] <= 236.0215) {
											if (features[20] <= 104.441) {
												if (features[3] <= 379.428) {
													return ( "metal");
												} else {
													return ( "rock");
												}
											} else {
												if (features[4] <= 552.6514999999999) {
													return ( "disco");
												} else {
													return ( "metal");
												}
											}
										} else {
											return ( "country");
										}
									} else {
										if (features[259] <= 337.6855) {
											if (features[0] <= 118.2165) {
												return ( "country");
											} else {
												if (features[0] <= 147.54) {
													return ( "disco");
												} else {
													return ( "metal");
												}
											}
										} else {
											if (features[7] <= 628.9165) {
												if (features[330] <= 108.031) {
													return ( "rock");
												} else {
													return ( "country");
												}
											} else {
												if (features[8] <= 499.19) {
													return ( "blues");
												} else {
													return ( "rock");
												}
											}
										}
									}
								}
							} else {
								if (features[85] <= 50.3932) {
									return ( "blues");
								} else {
									if (features[6] <= 607.5540000000001) {
										if (features[3] <= 609.018) {
											return ( "jazz");
										} else {
											return ( "classical");
										}
									} else {
										return ( "country");
									}
								}
							}
						}
					}
				} else {
					if (features[259] <= 1360.505) {
						if (features[5] <= 575.7294999999999) {
							if (features[151] <= 24.5462) {
								if (features[485] <= 0.7660165000000001) {
									if (features[113] <= 11.3219) {
										if (features[3] <= 743.992) {
											return ( "blues");
										} else {
											if (features[1] <= 582.7095) {
												return ( "jazz");
											} else {
												if (features[0] <= 159.8675) {
													return ( "country");
												} else {
													return ( "reggae");
												}
											}
										}
									} else {
										if (features[1] <= 469.273) {
											return ( "disco");
										} else {
											return ( "hiphop");
										}
									}
								} else {
									if (features[1] <= 1341.435) {
										if (features[33] <= 143.874) {
											if (features[1] <= 348.842) {
												if (features[0] <= 65.77305) {
													return ( "country");
												} else {
													return ( "disco");
												}
											} else {
												if (features[3] <= 280.937) {
													return ( "rock");
												} else {
													return ( "reggae");
												}
											}
										} else {
											return ( "jazz");
										}
									} else {
										if (features[6] <= 376.328) {
											return ( "hiphop");
										} else {
											if (features[0] <= 747.8505) {
												return ( "reggae");
											} else {
												return ( "rock");
											}
										}
									}
								}
							} else {
								if (features[1] <= 947.5540000000001) {
									if (features[9] <= 193.33499999999998) {
										if (features[0] <= 192.67350000000002) {
											return ( "country");
										} else {
											return ( "hiphop");
										}
									} else {
										return ( "disco");
									}
								} else {
									if (features[135] <= 53.5944) {
										if (features[5] <= 491.1565) {
											if (features[7] <= 187.52100000000002) {
												return ( "disco");
											} else {
												return ( "hiphop");
											}
										} else {
											if (features[0] <= 663.8910000000001) {
												return ( "jazz");
											} else {
												return ( "reggae");
											}
										}
									} else {
										return ( "reggae");
									}
								}
							}
						} else {
							if (features[480] <= 1.8924949999999998) {
								if (features[25] <= 227.69299999999998) {
									if (features[0] <= 661.892) {
										if (features[351] <= 15.62455) {
											return ( "jazz");
										} else {
											return ( "blues");
										}
									} else {
										if (features[0] <= 891.53) {
											return ( "metal");
										} else {
											return ( "reggae");
										}
									}
								} else {
									if (features[0] <= 155.9535) {
										return ( "rock");
									} else {
										return ( "country");
									}
								}
							} else {
								if (features[499] <= 23.9061) {
									if (features[219] <= 3.901315) {
										if (features[430] <= 26.184350000000002) {
											if (features[0] <= 420.5215) {
												return ( "country");
											} else {
												if (features[0] <= 440.3755) {
													return ( "reggae");
												} else {
													return ( "metal");
												}
											}
										} else {
											if (features[230] <= 1.05511) {
												if (features[0] <= 248.828) {
													return ( "disco");
												} else {
													return ( "blues");
												}
											} else {
												return ( "rock");
											}
										}
									} else {
										if (features[434] <= 24.61425) {
											if (features[14] <= 583.3615) {
												if (features[7] <= 611.9114999999999) {
													return ( "rock");
												} else {
													return ( "jazz");
												}
											} else {
												return ( "classical");
											}
										} else {
											if (features[111] <= 54.46065) {
												if (features[151] <= 39.1901) {
													return ( "country");
												} else {
													return ( "blues");
												}
											} else {
												if (features[9] <= 483.595) {
													return ( "disco");
												} else {
													return ( "jazz");
												}
											}
										}
									}
								} else {
									if (features[0] <= 343.7895) {
										if (features[7] <= 508.89250000000004) {
											if (features[0] <= 202.986) {
												return ( "pop");
											} else {
												if (features[1] <= 787.6625) {
													return ( "rock");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											return ( "disco");
										}
									} else {
										if (features[5] <= 599.021) {
											return ( "hiphop");
										} else {
											return ( "pop");
										}
									}
								}
							}
						}
					} else {
						if (features[35] <= 188.4855) {
							if (features[220] <= 2.542905) {
								if (features[0] <= 611.6015) {
									return ( "disco");
								} else {
									return ( "metal");
								}
							} else {
								if (features[104] <= 94.3625) {
									return ( "hiphop");
								} else {
									return ( "disco");
								}
							}
						} else {
							if (features[16] <= 230.48149999999998) {
								return ( "disco");
							} else {
								if (features[4] <= 1058.94) {
									if (features[0] <= 411.041) {
										return ( "hiphop");
									} else {
										return ( "reggae");
									}
								} else {
									return ( "blues");
								}
							}
						}
					}
				}
			} else {
				if (features[234] <= 11.13795) {
					if (features[70] <= 104.739) {
						if (features[371] <= 63.23995) {
							if (features[376] <= 53.508750000000006) {
								if (features[0] <= 200.267) {
									return ( "metal");
								} else {
									if (features[0] <= 228.49599999999998) {
										return ( "country");
									} else {
										return ( "rock");
									}
								}
							} else {
								return ( "disco");
							}
						} else {
							if (features[105] <= 73.78205) {
								return ( "blues");
							} else {
								if (features[4] <= 879.0409999999999) {
									if (features[0] <= 338.4755) {
										return ( "hiphop");
									} else {
										return ( "rock");
									}
								} else {
									return ( "disco");
								}
							}
						}
					} else {
						if (features[284] <= 310.739) {
							if (features[378] <= 39.238150000000005) {
								return ( "rock");
							} else {
								if (features[258] <= 2122.515) {
									if (features[353] <= 153.1995) {
										if (features[0] <= 695.118) {
											return ( "metal");
										} else {
											if (features[0] <= 769.9860000000001) {
												return ( "hiphop");
											} else {
												return ( "metal");
											}
										}
									} else {
										if (features[0] <= 403.304) {
											if (features[0] <= 123.28445) {
												return ( "reggae");
											} else {
												if (features[0] <= 243.169) {
													return ( "blues");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											return ( "metal");
										}
									}
								} else {
									if (features[0] <= 999.1055) {
										return ( "blues");
									} else {
										return ( "disco");
									}
								}
							}
						} else {
							if (features[311] <= 247.39749999999998) {
								if (features[3] <= 1514.575) {
									if (features[4] <= 975.854) {
										return ( "rock");
									} else {
										if (features[0] <= 625.1465) {
											return ( "disco");
										} else {
											return ( "hiphop");
										}
									}
								} else {
									return ( "metal");
								}
							} else {
								return ( "blues");
							}
						}
					}
				} else {
					if (features[258] <= 2246.145) {
						if (features[2] <= 2315.4049999999997) {
							if (features[278] <= 225.911) {
								if (features[39] <= 121.5135) {
									if (features[0] <= 175.4835) {
										return ( "reggae");
									} else {
										if (features[0] <= 207.017) {
											return ( "hiphop");
										} else {
											return ( "disco");
										}
									}
								} else {
									return ( "rock");
								}
							} else {
								if (features[150] <= 49.0389) {
									if (features[0] <= 157.463) {
										return ( "reggae");
									} else {
										return ( "pop");
									}
								} else {
									if (features[0] <= 875.892) {
										return ( "disco");
									} else {
										return ( "hiphop");
									}
								}
							}
						} else {
							if (features[12] <= 343.307) {
								if (features[0] <= 805.8415) {
									return ( "hiphop");
								} else {
									return ( "pop");
								}
							} else {
								return ( "country");
							}
						}
					} else {
						if (features[2] <= 3258.745) {
							return ( "hiphop");
						} else {
							return ( "reggae");
						}
					}
				}
			}
		} else {
			if (features[0] <= 244.131) {
				if (features[2] <= 1009.7049999999999) {
					if (features[0] <= 168.003) {
						return ( "reggae");
					} else {
						return ( "hiphop");
					}
				} else {
					return ( "disco");
				}
			} else {
				if (features[28] <= 113.745) {
					return ( "hiphop");
				} else {
					if (features[328] <= 297.71349999999995) {
						if (features[36] <= 86.44165) {
							return ( "reggae");
						} else {
							return ( "pop");
						}
					} else {
						if (features[0] <= 467.153) {
							return ( "reggae");
						} else {
							return ( "hiphop");
						}
					}
				}
			}
		}
	}
}